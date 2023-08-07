/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:56:19 by ajossera          #+#    #+#             */
/*   Updated: 2022/02/23 09:57:08 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_chevron(int i, char *str, int nb)
{
	if (nb == 0)
		return (i);
	if (str[i] == '<')
	{
		if (str[i + 1] == '<')
			return (i + 2);
		return (i + 1);
	}
	if (str[i] == '>')
	{
		if (str[i + 1] == '>')
			return (i + 2);
		return (i + 1);
	}
	if (str[i] == '|')
		return (i + 1);
	return (i);
}

int	ft_one_arg_second(char *str, int i)
{
	if (str[i] == '"')
	{
		while (str[++i] && str[i] != '"')
			;
		if (str[i] && str[++i] != ' ')
			i = ft_one_argument(str, i, 0);
		return (i);
	}
	if (str[i] == '\'')
	{
		while (str[++i] && str[i] != '\'')
			;
		if (str[i] && str[++i] != ' ')
			i = ft_one_argument(str, i, 0);
		return (i);
	}
	return (i);
}

int	ft_one_argument(char *str, int i, int nb)
{
	if (str[i] == 0)
		return (i);
	if (str[i] != '"' && str[i] != '\'')
	{
		if (str[i] == '<' || str[i] == '>' || str[i] == '|')
			return (ft_chevron(i, str, nb));
		while (str[++i] && str[i] != ' '
			&& str[i] != '<' && str[i] != '>' && str[i] != '|')
		{
			if (str[i] == '"' || str[i] == '\'')
			{
				i = ft_one_argument(str, i, 0);
				i--;
			}
		}
		return (i);
	}
	if (i != ft_one_arg_second(str, i))
		return (ft_one_arg_second(str, i));
	return (0);
}

char	**ft_secparsing(char *str, char	**ret, int finarg, int ntimes)
{
	int		i;
	int		nb_of_argument;
	int		new_i;
	int		x;

	i = 0;
	nb_of_argument = -1;
	while (++ntimes < finarg)
	{
		while (str[i] && str[i] == ' ')
			i++;
		new_i = ft_one_argument(str, i, 1) - i;
		ret[++nb_of_argument] = ft_calloc((new_i + 2), sizeof(char));
		if (!ret[nb_of_argument])
		{
			ft_free(ret);
			return (NULL);
		}
		x = -1;
		while (++x < new_i)
			ret[nb_of_argument][x] = str[i++];
		ret[nb_of_argument][x] = '\0';
	}
	ret[finarg] = NULL;
	return (ret);
}

char	**ft_parsing(char *str, t_list *envp, int i)
{
	int		nb_of_argument;
	char	**ret;

	nb_of_argument = 0;
	if (!str)
		return (NULL);
	str = ft_all_variable(str, envp, -1);
	if (!str)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		i = ft_one_argument(str, i, 1);
		nb_of_argument++;
		while (str[i] && str[i] == ' ')
			i++;
	}
	ret = ft_xmalloc((nb_of_argument + 1) * sizeof(char **));
	if (!ret)
		return (NULL);
	ret = ft_secparsing(str, ret, nb_of_argument, -1);
	free(str);
	return (ret);
}
