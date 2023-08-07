/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:43:27 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/22 13:50:56 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_error(char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit(-1);
}

void	check_exit2(char *arg, int sign, int i)
{
	unsigned long long	value;

	value = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			exit_error(arg);
		value = value * 10 + arg[i] - '0';
		if ((value > LLONG_MAX && sign > 0)
			|| (value > (unsigned long long)(-LLONG_MIN)
			&& sign < 0))
			exit_error(arg);
		i++;
	}
	if (arg[i] && !ft_isdigit(arg[i]))
		exit_error(arg);
}

void	check_exit(char *arg)
{
	int					i;
	int					sign;

	i = 0;
	sign = 1;
	ft_putstr_fd("exit\n", 2);
	if (!arg)
		exit(g_exit_value);
	if ((arg[i] == '+' || arg[i] == '-') && arg[i + 1])
	{
		if (arg[i] == '-')
			sign *= -1;
		i++;
	}
	check_exit2(arg, sign, i);
}

void	ft_exit2(char **arg, t_sh *sh)
{
	int	value;
	int	sign;
	int	i;

	close(sh->stdin_fd);
	close(sh->stdout_fd);
	value = 0;
	sign = 1;
	i = 0;
	check_exit(arg[0]);
	if (arg[0] && arg[1])
		return (ft_putstr_fd("minishell: exit: too many arguments\n", 2));
	if (arg[0][i] == '+' || arg[0][i] == '-')
	{
		if (arg[0][i] == '-')
			sign *= -1;
		i++;
	}
	while (arg[0][i] >= '0' && arg[0][i] <= '9')
	{
		value = value * 10 + arg[0][i] - '0';
		i++;
	}
	value *= sign;
	exit(value);
}
