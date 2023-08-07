/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:27:43 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/03 17:42:08 by tlafay           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(void *str, int c, int size)
{
	unsigned char	*p;

	p = str;
	while (size--)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
	}
	return (0);
}
