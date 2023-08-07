/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajossera <ajossera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:13:45 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/22 18:41:08 by ajossera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_value = 0;

int	ft_is_chevron(char	*str)
{
	if ((str[0] == '<' || str[0] == '>' || str[0] == '|') && str[1] == 0)
		return (1);
	if (str[0] == '<' && str[1] == '<' && str[2] == 0)
		return (1);
	if (str[0] == '>' && str[1] == '>' && str[2] == 0)
		return (1);
	return (0);
}

int	ft_read_chevron_two(char *str, char *arg)
{
	if (!arg)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (1);
	}
	if (ft_is_chevron(str))
	{
		if (!arg)
		{
			printf("minishell: syntax error near unexpected token `%s'\n", str);
			return (1);
		}
		if (ft_is_chevron(arg))
		{
			printf("minishell: syntax error near unexpected token `%s'\n", arg);
			return (1);
		}
		if (arg[0] == '|' && arg[1] == 0)
		{
			printf("minishell: syntax error near unexpected token `%s'\n", arg);
			return (1);
		}
	}
	return (-1);
}

int	ft_read_chevron(char *str, char *arg, t_sh *sh)
{
	if (ft_read_chevron_two(str, arg) != -1)
		return (ft_read_chevron_two(str, arg));
	if (str[0] == '>' && str[1] == 0)
		return (redirect_out(ft_change_arg(arg)));
	if (str[0] == '<' && str[1] == 0)
		return (redirect_in(ft_change_arg(arg)));
	if (str[0] == '>' && str[1] == '>' && str[2] == 0)
		return (redirect_out_append(ft_change_arg(arg)));
	if (str[0] == '<' && str[1] == '<' && str[2] == 0)
		return (heredoc(ft_change_arg(arg),
				sh->stdin_fd, sh->stdout_fd, sh->env));
	return (0);
}

char	**ft_make_cmd2(char **argv, int *nbr, int *error, t_sh *sh)
{
	char	**cmd;

	cmd = NULL;
	while (argv[*nbr])
	{
		if (!ft_strncmp("|", argv[*nbr], 1) && ft_strlen(argv[*nbr]) == 1)
			break ;
		if (ft_is_chevron(argv[*nbr]) && !*error)
		{
			g_exit_value = ft_read_chevron(argv[*nbr], argv[*nbr + 1], sh);
			if (g_exit_value)
				*error = 1;
			(*nbr)++;
		}
		else if (!*error)
			cmd = ft_add_cmd(ft_change_arg(ft_strdup(argv[*nbr])), cmd);
		if (argv[*nbr])
			(*nbr)++;
	}
	return (cmd);
}

int	ft_make_cmd(char **argv, t_sh *sh, int *i, int j)
{
	char	**cmd;
	int		nbr;
	int		error;

	nbr = 0;
	error = 0;
	cmd = NULL;
	cmd = ft_make_cmd2(argv, &nbr, &error, sh);
	if (!error)
		ft_redirect_cmd(sh, cmd, j);
	ft_free(cmd);
	*i += nbr;
	return (error);
}
