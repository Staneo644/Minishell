/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajossera <ajossera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:50:54 by tlafay            #+#    #+#             */
/*   Updated: 2022/02/22 18:23:48 by ajossera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*envp_error(char *command)
{
	ft_putstr_fd("minishell: ", 2);
	perror(command + 1);
	free(command);
	return (NULL);
}

char	*path_error(char *command)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command + 1, 2);
	ft_putstr_fd(": command not found\n", 2);
	free(command);
	return (NULL);
}

char	*valid_path2(char *command, char **split)
{
	int		i;
	char	*tmp;

	i = 0;
	while (split[i])
	{
		tmp = ft_strjoin(split[i], command);
		if (access(tmp, X_OK) == 0)
		{
			ft_free(split);
			free(command);
			return (tmp);
		}
		free(tmp);
		tmp = NULL;
		i++;
	}
	ft_free(split);
	return (NULL);
}

char	*valid_path(char *command, char **envp)
{
	int		i;
	char	**split;
	char	*tmp;

	if (!envp)
		return (NULL);
	if (access(command, X_OK) == 0)
		return (command);
	i = -1;
	command = ft_strjoinf("/", command);
	while (envp[++i])
	{
		split = ft_split(envp[i], '=');
		if (ft_strncmp(split[0], "PATH", 4) == 0)
			break ;
		ft_free(split);
	}
	if (!envp[i])
		return (envp_error(command));
	ft_free(split);
	tmp = valid_path2(command, ft_split(envp[i] + 5, ':'));
	if (tmp)
		return (tmp);
	return (path_error(command));
}

int	command_exec(char **cmd, char **envp, int fd)
{
	int	pid;

	*cmd = valid_path(*cmd, envp);
	pid = fork();
	if (pid == 0)
	{
		if (fd != -1)
			close(fd);
		if (*cmd)
		{
			execve(*cmd, cmd, envp);
			perror("minishell: execvp");
		}
		ft_free(envp);
		ft_free(cmd);
		exit(127);
	}
	ft_free(envp);
	return (0);
}
