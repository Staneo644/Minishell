/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:55:07 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/11 10:40:34 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*p;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	s = (unsigned char *)src;
	p = dest;
	while (size--)
	{
		*p = *s;
		p++;
		s++;
	}
	return (dest);
}
