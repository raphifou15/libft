/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 12:23:05 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/13 18:24:54 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *list_chain;

	list_chain = malloc(sizeof(t_list));
	if (list_chain == 0)
		return (0);
	list_chain->content = content;
	list_chain->next = NULL;
	return (list_chain);
}
