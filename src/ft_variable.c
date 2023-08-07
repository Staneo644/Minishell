/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:50:08 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/23 15:37:04 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_have_variable(int i, char **str, char *a, int pj)
{
	int		endvar;
	char	*memo;

	a = ft_change_chevron(a, pj);
	endvar = i;
	while (str[0][++endvar] && ft_isalpha(str[0][endvar]))
		;
	memo = ft_str(&(str[0][endvar]));
	str[0][i] = '\0';
	*str = ft_strfjoin(str[0], &(a[pj]));
	endvar = ft_strlen(*str);
	*str = ft_strffjoin(str[0], memo);
	free(a);
	return (endvar);
}

int	ft_variable_two(int i, char **str, int endvar, char *a)
{
	char	charmem;
	int		pj;

	pj = -1;
	charmem = str[0][endvar];
	while (a[++pj])
	{
		if (a[pj] == '=')
		{
			a[pj] = '\0';
			str[0][endvar] = '\0';
			if (ft_strncmp(a, &(str[0][i + 1]),
				ft_strlen(&(str[0][i + 1])) + 1) == 0)
			{
				str[0][endvar] = charmem;
				a[pj] = '=';
				return (ft_have_variable(i, str, ft_strdup(a), pj + 1));
			}
			str[0][endvar] = charmem;
			a[pj] = '=';
		}
	}
	return (-1);
}

int	ft_variable(int i, char **str, t_list *envp)
{
	int		endvar;
	int		io;

	if (ft_have_problem(i, str))
		return (ft_check_variable(i, str));
	endvar = i;
	while (str[0][++endvar] && ft_isalpha(str[0][endvar]))
		;
	while (envp)
	{
		io = ft_variable_two(i, str, endvar, envp->content);
		if (io != -1)
			return (io);
		envp = envp->next;
	}
	str[0][i] = '\0';
	if (str[0][endvar])
		*str = ft_strfjoin(str[0], &(str[0][endvar]));
	else
		*str = ft_strfjoin(str[0], NULL);
	return (i);
}

char	*ft_all_variable(char *str, t_list *envp, int i)
{
	while (str[++i])
	{
		if (str[i] == '$')
			i = ft_variable(i, &str, envp) - 1;
		if (!str)
			return (NULL);
		if (str[i] == '"')
		{
			while (str[++i] && str[i] != '"')
			{
				if (str[i] == '$')
					i = ft_variable(i, &str, envp) - 1;
				if (!str)
					return (NULL);
			}
		}
		if (str[i] == '\'')
			while (str[++i] && str[i] != '\'')
				;
		if (str[i] == 0)
			return (str);
	}
	return (str);
}
