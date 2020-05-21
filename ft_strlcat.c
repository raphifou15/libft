/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 08:55:46 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/04 12:00:24 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dst_max;
	size_t src_max;

	i = 0;
	while (dst[i] != '\0')
		i++;
	dst_max = i;
	i = 0;
	while (src[i] != '\0')
		i++;
	src_max = i;
	i = 0;
	if (dst_max > size)
		return (src_max + size);
	while (src[i] != '\0' && size > (dst_max + i + 1))
	{
		dst[dst_max + i] = src[i];
		i++;
	}
	dst[dst_max + i] = '\0';
	return (src_max + dst_max);
}
