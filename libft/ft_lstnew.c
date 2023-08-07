/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:31:23 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/10 15:46:10 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)ft_xmalloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
