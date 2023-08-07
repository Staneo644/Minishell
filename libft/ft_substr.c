/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:00:31 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/11 14:47:41 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	int		p;

	p = start;
	i = 0;
	if ((size_t)ft_strlen(s) < len)
		new = (char *)ft_xmalloc((ft_strlen(s) + 1) * sizeof(char));
	else
		new = (char *)ft_xmalloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < len && p < ft_strlen(s))
	{
		new[i] = s[p];
		i++;
		p++;
	}
	new[i] = '\0';
	return (new);
}
