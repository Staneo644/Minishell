/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafay <tlafay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 07:53:01 by tlafay            #+#    #+#             */
/*   Updated: 2021/11/10 14:47:49 by tlafay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*head;

	if (!lst)
		return (NULL);
	head = lst;
	while (head->next != NULL)
		head = head->next;
	return (head);
}
