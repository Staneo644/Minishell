/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:43:04 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/23 12:08:11 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free_one(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (0);
}

void	handle_sigint(int sig)
{
	(void)sig;
	g_exit_value = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sig_handle(int sig)
{
	g_exit_value += 128 + sig;
	if (sig == SIGINT)
		printf("\n");
	if (sig == SIGQUIT)
		printf("Quit: 3\n");
}

int	ft_add_arg(char *arg, t_sh *sh)
{
	while (arg && *arg == ' ')
		arg++;
	if (!arg)
	{
		printf("\033[1A\033[3C");
		return (0);
	}
	else if (arg[0])
	{
		if (ft_all_space(arg))
			return (1);
		sh->argv = ft_parsing(ft_strdup(arg), sh->env, 0);
		if (!sh->argv)
			ft_exit("MALLOC ERROR");
		signal(SIGINT, sig_handle);
		signal(SIGQUIT, sig_handle);
		signal(SIGTERM, sig_handle);
		ft_redirect_pipe(sh->argv, sh);
		ft_free(sh->argv);
		add_history(arg);
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char	*ret;
	t_sh	sh;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	ft_init_env(&(sh.env), envp);
	sh.close = 1;
	if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'c')
	{
		if (argc >= 3)
			ft_add_arg(argv[2], &sh);
		else
			printf("minishell: -c: option requires an argument\n");
		return (g_exit_value);
	}
	while (1)
	{
		ret = readline("$> ");
		if (!ft_add_arg(ret, &sh))
			break ;
		free(ret);
	}
	ft_lstclear(&(sh.env), (void *)&ft_free_one);
	printf("exit\n");
	return (g_exit_value);
}
