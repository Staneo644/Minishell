/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:00:54 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/02 15:41:45 by tlafay           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *pointer, int value, int count)
{
	unsigned char	*p;

	p = pointer;
	while (count--)
	{
		*p = (unsigned char)value;
		p++;
	}
	return (pointer);
}
