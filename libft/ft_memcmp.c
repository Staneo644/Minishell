/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:01:41 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/06 10:47:42 by tlafay           ###   ########.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *p1, void *p2, size_t size)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = p1;
	s2 = p2;
	i = 0;
	if (size == 0)
		return (0);
	while (s1[i] == s2[i] && i < size - 1)
		i++;
	return (s1[i] - s2[i]);
}
