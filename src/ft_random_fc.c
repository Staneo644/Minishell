/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_fc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajossera <ajossera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:09:02 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/22 18:24:21 by ajossera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i])
			free(str[i]);
		str[i] = NULL;
	}
	if (str)
		free(str);
	str = NULL;
	return (0);
}

int	ft_all_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (i != ' ')
			return (0);
	}
	return (1);
}

char	*ccut(char *str, char c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)ft_xmalloc((ft_strlen(str) + 1) * sizeof(char));
	if (!ret)
		exit(1);
	while (str[i] && str[i] != c)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	atoi_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (1);
		i++;
	}
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
