/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 20:08:39 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/18 14:41:42 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;
	t_list	*new_new;
	void	*newcontent;

	node = lst;
	newlist = NULL;
	if (!lst)
		return (NULL);
	while (node)
	{
		newcontent = (*f)(node->content);
		new_new = ft_lstnew(newcontent);
		if (!new_new)
			ft_lstdelone(node, (del));
		ft_lstadd_back(&newlist, new_new);
		node = node->next;
	}
	return (newlist);
}
