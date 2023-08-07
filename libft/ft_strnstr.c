/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:21:59 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/05 17:17:41 by tlafay           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *search, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	n = 0;
	i = 0;
	if (!search[0])
		return ((char *)str);
	while (str[i] && n < len)
	{
		j = 0;
		while (search[j] == str[i + j] && i + j < len)
		{
			if (!search[j + 1])
				return ((char *)&str[i]);
			j++;
		}
		i++;
		n++;
	}
	return (0);
}
