/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:54:32 by tlafay            #+#    #+#             */
/*   Updated: 2022/01/04 13:21:38 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_count(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	word_count(char const *str, char c)
{
	int		i;
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		i = len_count(str, c);
		str += i;
		if (i)
			count++;
	}
	return (count);
}

static char	*ft_strcpy(char const *src, int j)
{
	char	*dst;
	int		i;

	i = 0;
	dst = ft_xmalloc((j + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < j && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	ft_free(char **str, int i)
{
	int	j;

	j = 0;
	if (!str[i])
	{
		while (j < i)
		{
			free(str[j]);
			j++;
		}
		free(str);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		size;

	if (!s)
		return (NULL);
	size = word_count(s, c);
	i = 0;
	ret = ft_xmalloc((size + 1) * sizeof(char *));
	if (!ret)
		return (0);
	while (i < size)
	{
		while (*s == c && *s)
			s++;
		j = len_count(s, c);
		ret[i] = ft_strcpy(s, j);
		if (ft_free(ret, i))
			return (NULL);
		s += j;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
