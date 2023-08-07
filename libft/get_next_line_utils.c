/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:41:06 by tlafay            #+#    #+#             */
/*   Updated: 2022/02/22 17:19:34 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	ret = (char *)ft_xmalloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ft_free2(s1);
	ret[i + j] = '\0';
	return (ret);
}

void	ft_strcpy2(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (!s2)
	{
		while (s1[i])
		{
			s1[i] = '\0';
			i++;
		}
	}
	else
	{
		while (s2[i])
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
}
