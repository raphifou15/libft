/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:41:12 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/12 16:22:50 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_write(int n, int size, int fd)
{
	int		i;
	long	new_number;

	new_number = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		new_number = (new_number * -1);
	}
	i = 0;
	while (9 < size)
	{
		ft_putchar_fd(((new_number / size) + 48), fd);
		new_number = new_number % size;
		size /= 10;
		i++;
	}
	ft_putchar_fd(new_number + 48, fd);
}

static int		ft_size(int n)
{
	int size;

	size = 1;
	if (n == -2147483648)
		n = -2147483647;
	if (n < 0)
		n = n * (-1);
	while (n > 9)
	{
		n = n / 10;
		size *= 10;
	}
	return (size);
}

void			ft_putnbr_fd(int n, int fd)
{
	int size;

	size = ft_size(n);
	ft_write(n, size, fd);
}
