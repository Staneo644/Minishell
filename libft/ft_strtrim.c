/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:38:56 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/09 13:20:36 by tlafay           ###   ########.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	cmp(int i, int j)
{
	if (i > j)
		return (i - j);
	return (j - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		j;
	int		k;	

	i = 0;
	while (is_in_set(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (is_in_set(s1[j], set) && j)
		j--;
	j++;
	ret = (char *)ft_xmalloc((cmp(i, j) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	k = 0;
	while (i < j)
		ret[k++] = s1[i++];
	ret[k] = '\0';
	return (ret);
}
