/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 22:27:07 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/15 00:21:05 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	if (new == NULL)
		return;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	temp = *alst;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}
