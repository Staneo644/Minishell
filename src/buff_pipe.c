/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:57:02 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/21 17:53:27 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_buf(t_list *env)
{
	t_list	*tmp;
	int		i;
	char	**ret;

	ret = (char **)ft_xmalloc((ft_lstsize(env) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	tmp = env;
	i = 0;
	while (tmp)
	{
		if (ft_strchr(tmp->content, '='))
			ret[i++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	ret[i] = NULL;
	return (ret);
}

int	ft_pipe(int fd, int end)
{
	int	pipe_fd[2];

	if (fd != -1)
	{
		if (dup2(fd, 0) == -1)
			perror("minishell: dup2");
		close(fd);
	}
	if (!end)
	{
		if (pipe(pipe_fd) == -1)
			perror("minishell: pipe");
		if (dup2(pipe_fd[1], 1) == -1)
			perror("minishell: dup2");
		close(pipe_fd[1]);
		return (pipe_fd[0]);
	}
	return (-1);
}
