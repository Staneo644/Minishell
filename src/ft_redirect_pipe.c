/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:14:29 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/22 14:08:08 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_end(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_strncmp("|", argv[i], 1))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_two_pipe(char **argv)
{
	int	i;

	i = 0;
	if (argv[0][0] == '|' && argv[0][1] == 0)
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (1);
	}
	while (argv[++i])
	{
		if (argv[i - 1][0] == '|' && argv[i - 1][1] == 0)
		{
			if (argv[i][0] == '|' && argv[i][1] == 0)
			{
				ft_putstr_fd(
					"minishell: syntax error near unexpected token `|'\n", 1);
				return (1);
			}
		}
	}
	return (0);
}

int	ft_redirect_pipe2(t_sh *sh, char **argv)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	j = 0;
	while (argv[i])
	{
		sh->pipe_fd = ft_pipe(sh->pipe_fd, is_end(&argv[i]));
		error = ft_make_cmd(&argv[i], sh, &i, j);
		if (!error)
			j++;
		dup2(sh->stdin_fd, 0);
		dup2(sh->stdout_fd, 1);
		if (argv[i])
			i++;
	}
	close(sh->stdin_fd);
	close(sh->stdout_fd);
	g_exit_value = 0;
	g_exit_value += error;
	return (j);
}

int	ft_redirect_pipe(char **argv, t_sh *sh)
{
	int	i;
	int	j;

	sh->pipe_fd = -1;
	i = 0;
	j = 0;
	if (ft_check_two_pipe(argv))
		return (1);
	sh->stdin_fd = dup(0);
	sh->stdout_fd = dup(1);
	j = ft_redirect_pipe2(sh, argv);
	while (j--)
	{
		wait(&i);
		g_exit_value += WEXITSTATUS(i);
	}
	return (0);
}
