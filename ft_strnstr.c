/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:51:48 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/20 21:52:44 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char			*str1;
	unsigned int	i;
	unsigned int	j;
	int				res;

	res = -1;
	j = 0;
	i = 0;
	str1 = (char *)big;
	if (little[i] == '\0')
		return (str1);
	while (i < ft_strlen(big) && i < len && res == -1)
	{
		while (big[i] == little[j] && i < len && big[i] != '\0')
		{
			i++;
			j++;
			if (little[j] == '\0')
				res = i - j;
		}
		i = (j > 0) ? i - j : i;
		j = 0;
		(res != -1) ? i-- : i++;
	}
	return (res != -1) ? (str1 + res) : NULL;
}
