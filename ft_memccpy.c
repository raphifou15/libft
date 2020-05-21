/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:38:36 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/02 22:38:42 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	str_dest = (unsigned char *)dest;
	str = (unsigned char *)src;
	c = (unsigned char)c;
	while (i < n)
	{
		str_dest[i] = str[i];
		if (str[i] == c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
