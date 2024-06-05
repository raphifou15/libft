/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 10:06:46 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/04 12:07:31 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c == -1)
		return -1;
	c = (unsigned char)(c);
	if (c >= 'A' && c <= 'Z')
	{
		c += ('a' - 'A');
		return (c);
	}
	return (c);
}
