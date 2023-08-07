/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:40:12 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/22 14:04:22 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_write(char **argv, int i, int type)
{
	while (argv[++i])
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1])
			write(1, " ", 1);
	}
	if (type == 1)
		write(1, "\n", 1);
}

void	ft_echo(char **argv)
{
	int	i;
	int	type;
	int	number_n;
	int	loop;

	loop = 1;
	type = 1;
	i = 0;
	number_n = 1;
	while (loop && argv[1 + i] && ft_strncmp(argv[1 + i], "-n", 2) == 0)
	{
		while (argv[1 + i][++number_n] == 'n')
			;
		if (argv[1 + i][number_n] == '\0')
			type = 0 * i++;
		else
			loop = 0;
		number_n = 1;
	}
	ft_write(argv, i, type);
}
