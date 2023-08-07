/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:23:20 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/04 12:17:51 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)ft_xmalloc(ft_strlen(src) + 1);
	if (ret == NULL)
		return (0);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
