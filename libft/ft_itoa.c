/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:01:22 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/09 09:44:18 by tlafay           ###   ########.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit_num(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	get_tab(int i, long s, char *ret)
{
	if (s < 0)
	{
		ret[0] = '-';
		s *= -1;
	}
	while (s > 0)
	{
		ret[i] = '0' + (s % 10);
		s /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	long	s;
	int		i;
	char	*ret;

	s = n;
	i = digit_num(n);
	ret = (char *)ft_xmalloc((i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[i--] = '\0';
	if (s == 0)
	{
		ret[0] = 48;
		return (ret);
	}
	get_tab(i, s, ret);
	return (ret);
}
