/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajossera <ajossera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:49:49 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/22 18:31:03 by ajossera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_in(char *filein)
{
	int	fd;

	fd = open(filein, O_RDONLY);
	if (fd == -1)
	{
		perror("minishell");
		return (1);
	}
	if (dup2(fd, 0) == -1)
	{
		perror("minishell: dup2");
		return (1);
	}
	close(fd);
	return (0);
}

int	redirect_out(char *fileout)
{
	int	fd;

	fd = open(fileout, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		perror("minishell");
		return (1);
	}
	if (dup2(fd, 1) == -1)
	{
		perror("minishell: dup2");
		return (1);
	}
	close(fd);
	return (0);
}

int	redirect_out_append(char *fileout)
{
	int	fd;

	fd = open(fileout, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
	{
		perror("minishell");
		return (1);
	}
	if (dup2(fd, 1) == -1)
	{
		perror("minishell: dup2");
		return (1);
	}
	close(fd);
	return (0);
}
