/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 15:45:45 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/11 13:17:25 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned	int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (size == 0)
		return (j);
	while (i < (size - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
