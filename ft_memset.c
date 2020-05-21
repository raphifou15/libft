/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:42:29 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/02 22:42:38 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char cc;

	str = (unsigned char *)s;
	cc = (unsigned char)c;
	while (0 < n)
	{
		str[n - 1] = cc;
		n--;
	}
	return (s);
}
