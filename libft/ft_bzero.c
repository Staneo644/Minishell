/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:43:06 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/02 15:49:34 by tlafay           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, int n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p = '\0';
		p++;
	}
}