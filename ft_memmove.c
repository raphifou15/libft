/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:41:48 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/04 18:28:43 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	str_dest = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (!str_dest && !str)
		return (0);
	if (str_dest > str)
	{
		while (i < n)
		{
			str_dest[n - 1 - i] = str[n - 1 - i];
			i++;
		}
	}
	else
	{
		while (i++ < n)
			str_dest[i - 1] = str[i - 1];
	}
	return (dest);
}
