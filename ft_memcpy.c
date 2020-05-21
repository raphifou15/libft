/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:41:03 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/02 22:51:40 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str_dest;

	str = (unsigned char *)src;
	str_dest = (unsigned char *)dest;
	if (!str && !str_dest)
		return (0);
	while (n > 0)
	{
		str_dest[n - 1] = str[n - 1];
		n--;
	}
	return (dest);
}
