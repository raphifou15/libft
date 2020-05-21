/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:58:05 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/19 09:34:03 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;

	if (*lst == NULL)
		return ;
	node = *lst;
	while (node)
	{
		temp = node->next;
		(*del)(node->content);
		free(node);
		node = NULL;
		node = temp;
	}
	*lst = NULL;
}
