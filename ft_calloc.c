/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 07:06:13 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/05 10:25:38 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*str;

	str = malloc(nmemb * size);
	if (str == NULL)
		return (0);
	nmemb = size * nmemb;
	while (nmemb > 0)
	{
		str[nmemb - 1] = 0;
		nmemb--;
	}
	return (str);
}
