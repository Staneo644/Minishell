/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:35:48 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/09 08:40:36 by tlafay           ###   ########.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	tmp = (char *)ft_xmalloc((ft_strlen(s) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (s[i])
	{
		tmp[i] = (*f)(i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
