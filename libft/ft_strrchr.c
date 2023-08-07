/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:58:09 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/11 12:10:05 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(char *str, int search)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	while (i >= 0)
	{
		if ((unsigned char)*str == (unsigned char)search)
			return (str);
		str--;
		i--;
	}
	return (0);
}
