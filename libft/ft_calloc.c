/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:07:12 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/05 11:33:47 by tlafay           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	void	*ptr;
	char	*tmp;
	int		taille;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	tmp = ptr;
	taille = count * size;
	while (taille--)
		*tmp++ = 0;
	return (ptr);
}
