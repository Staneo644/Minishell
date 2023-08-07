/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:42:12 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/11 12:09:40 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int search)
{
	char	*s;

	s = (char *)str;
	while ((unsigned char)*s != (unsigned char)search)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}
