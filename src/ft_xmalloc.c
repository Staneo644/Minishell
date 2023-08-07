/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:21:16 by tlafay            #+#    #+#             */
/*   Updated: 2022/02/22 14:27:45 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_xmalloc(int size)
{
	void	*ptr;

	ptr = ft_calloc(size, 1);
	if (!ptr)
	{
		ft_putstr_fd("minishell: couldn't allocate memory -- aborting", 2);
		exit(1);
	}
	return (ptr);
}
