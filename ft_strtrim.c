/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 15:14:22 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/10 01:47:11 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wheel(char const *s1, char const *set, int i)
{
	int	j;

	j = 0;
	while (s1[i] != '\0' && set[j] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				i++;
				j = -1;
			}
			j++;
		}
	}
	return (i);
}

static int		ft_end_wheel(char const *s1, char const *set, int i)
{
	int j;

	j = 0;
	while (i > 0 && set[j] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s1[i - 1] == set[j])
			{
				i--;
				j = -1;
			}
			j++;
		}
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		index;
	int		len;
	char	*str;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	index = ft_wheel(s1, set, i);
	i = ft_strlen(s1);
	i = ft_end_wheel(s1, set, i);
	if (i == 0)
	{
		str = malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		*str = '\0';
		return (str);
	}
	else
	{
		i = ft_strlen(s1) - i;
		len = ft_strlen(s1) - i - index;
	}
	return (ft_substr(s1, (unsigned int)index, (size_t)len));
}
