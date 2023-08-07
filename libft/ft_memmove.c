/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:46:32 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/03 08:31:59 by tlafay           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, void *src, int size)
{
	unsigned char	*d;
	unsigned char	*s;

	s = src;
	d = dest;
	if ((d == 0) && (s == 0))
		return (0);
	if ((s < d) && (d < s + size))
	{
		s += size;
		d += size;
		while (size--)
			*--d = *--s;
	}
	else
	{	
		while (size--)
			*d++ = *s++;
	}
	return (dest);
}
