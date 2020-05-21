/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 10:55:50 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/06 14:55:37 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		size_chains;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	size_chains = i;
	i = ft_strlen(s2);
	size_chains = size_chains + i;
	i = -1;
	if ((str = malloc(sizeof(char) * size_chains + 1)) == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	size_chains = -1;
	while (s2[++size_chains] != '\0')
	{
		str[i] = s2[size_chains];
		i++;
	}
	str[i] = '\0';
	return (str);
}
