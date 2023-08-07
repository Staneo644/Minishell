/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chevron_check_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:04:20 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/23 12:25:29 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_second_check_variable(int i, char **str)
{
	char	*memo;

	if (str[0][i + 1] == '"' || str[0][i + 1] == '\'')
	{
		str[0][i] = 0;
		str[0] = ft_strfjoin(str[0], &(str[0][i + 1]));
		return (i);
	}
	if (str[0][i + 1] == 0 || str[0][i + 1] == ' ' || str[0][1 + i] == '>'
		|| str[0][1 + i] == '<' || str[0][1 + i] == '|')
		return (i + 1);
	if (str[0][i + 1] == '?')
	{
		memo = ft_str(&(str[0][i + 2]));
		str[0][i] = 0;
		*str = ft_strffjoin(*str, ft_itoa(g_exit_value));
		*str = ft_strffjoin(*str, memo);
		return (i + 2);
	}
	return (-1);
}

int	ft_have_problem(int i, char **str)
{
	int		a;

	a = i - 1;
	while (--a > 0 && str[0][a] == ' ')
		;
	if (str[0][a] == '<' && a > 0 && str[0][a - 1] == '<')
		return (1);
	if (str[0][i + 1] == 0 || str[0][i + 1] == ' ' || str[0][1 + i] == '>'
		|| str[0][1 + i] == '<' || str[0][1 + i] == '|')
		return (1);
	if (str[0][i + 1] == '"' || str[0][i + 1] == '\'')
		return (1);
	if (str[0][i + 1] == '?')
		return (1);
	return (0);
}

int	ft_check_variable(int i, char **str)
{
	int		a;

	a = i - 1;
	while (--a > 0 && str[0][a] == ' ')
		;
	if (str[0][a] == '<' && a > 0 && str[0][a - 1] == '<')
	{
		while (str[0][++i] && ft_isalpha(str[0][i]))
			;
		return (i);
	}
	return (ft_second_check_variable(i, str));
}

int	ft_second_change_chevron(char **str, int pj, int i)
{
	char	mem;
	char	*memstr;

	memstr = ft_str(&(str[0][pj + i + 1]));
	mem = str[0][pj + i];
	str[0][i + pj] = 0;
	str[0] = ft_strfjoin(str[0], "\"");
	if (!memstr || !str[0])
		return (-1);
	str[0] = ft_strfjoin(str[0], &mem);
	if (!str[0])
		return (-1);
	str[0] = ft_strfjoin(str[0], "\"");
	if (!str[0])
		return (-1);
	str[0] = ft_strffjoin(str[0], memstr);
	if (!str[0])
		return (-1);
	i++;
	return (i);
}

char	*ft_change_chevron(char *str, int pj)
{
	int		i;

	i = -1;
	if (!str)
		return (str);
	while (str[pj + (++i)])
	{
		if (str[pj + i] == '"')
			while (str[pj + (++i)] && str[pj + i] != '"')
				;
		if (str[pj + i] == '\'')
			while (str[pj + (++i)] && str[pj + i] != '\'')
				;
		if (str[pj + i] == '|' || str[pj + i] == '<' || str[pj + i] == '>')
			i = ft_second_change_chevron(&str, pj, i);
		if (i == -1)
			return (NULL);
	}
	return (str);
}
