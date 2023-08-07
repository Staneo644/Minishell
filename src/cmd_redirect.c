/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:35:22 by tlafay            #+#    #+#             */
/*   Updated: 2022/02/22 17:22:28 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = -1;
	if (!str1 || !str2)
		return (-1);
	if (!str1[0] || !str2[0])
		return (str1[0] - str2[0]);
	while (str1[++i] && str1[i] == str2[i])
		;
	return (str1[i] - str2[i]);
}

int	ft_change_when_chev(char **str, int i, char c)
{
	str[0][i] = '\0';
	str[0] = ft_strfjoin(str[0], &(str[0][i + 1]));
	while (str[0][i] && str[0][i] != c)
		i++;
	if (str[0][i] == c)
	{
		str[0][i] = '\0';
		str[0] = ft_strfjoin(str[0], &(str[0][i + 1]));
	}
	return (i);
}

char	*ft_change_arg(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		while (str[i] == '"' || str[i] == '\'')
		{
			if (str[i] == '"')
				i = ft_change_when_chev(&str, i, '"');
			if (str[i] == '\'')
			{
				i = ft_change_when_chev(&str, i, '\'');
			}
		}
		if (!str[i])
			return (str);
	}
	return (str);
}

int	ft_redirect_cmd(t_sh *sh, char **cmd, int j)
{
	if (!cmd)
		return (1);
	else if (ft_strcmp(cmd[0], "exit") == 0 && !j)
		ft_exit2(cmd + 1, sh);
	else if (ft_strcmp(cmd[0], "echo") == 0 && !j)
		ft_echo(cmd);
	else if (ft_strcmp(cmd[0], "env") == 0 && !j)
		ft_env(sh->env);
	else if (ft_strcmp(cmd[0], "export") == 0 && !j)
		ft_export(cmd + 1, &(sh->env));
	else if (ft_strcmp(cmd[0], "unset") == 0 && !j)
		ft_unset(cmd, &(sh->env));
	else if (ft_strcmp(cmd[0], "cd") == 0 && !j)
		ft_cd(cmd[1], &(sh->env));
	else if (ft_strcmp(cmd[0], "pwd") == 0 && !j)
		ft_pwd();
	else
		command_exec(cmd, list_to_buf(sh->env), sh->pipe_fd);
	return (1);
}
