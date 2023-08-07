/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:31:06 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/23 09:57:14 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_sigint(int sig)
{
	(void)sig;
	exit(1);
}

void	heredoc2(char *delimiter, int stdin_fd, int stdout_fd, t_list *env)
{
	int		heredoc_fd;
	char	*str;

	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, SIG_IGN);
	heredoc_fd = open("/tmp/.heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (heredoc_fd == -1)
		perror("minishell: heredoc");
	while (1)
	{
		write(stdout_fd, "> ", 2);
		str = get_next_line(stdin_fd);
		if ((ft_strncmp(delimiter, str, ft_strlen(delimiter)) == 0
				&& ft_strlen(delimiter) == ft_strlen(str) - 1) || !str)
			break ;
		str = ft_all_variable(str, env, -1);
		write(heredoc_fd, str, ft_strlen(str));
		free(str);
	}
	close(heredoc_fd);
	close(stdout_fd);
	close(stdin_fd);
	exit(0);
}

int	heredoc(char *delimiter, int stdout_fd, int stdin_fd, t_list *env)
{
	int		heredoc_fd;
	int		pid;
	int		status;

	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (!pid)
		heredoc2(delimiter, stdin_fd, stdout_fd, env);
	wait(&status);
	if (WEXITSTATUS(status) == 0)
	{
		heredoc_fd = open("/tmp/.heredoc", O_RDONLY);
		if (heredoc_fd == -1)
			perror("minishell: heredoc");
		dup2(heredoc_fd, 0);
		close(heredoc_fd);
	}
	unlink("/tmp/.heredoc");
	return (WEXITSTATUS(status));
}
