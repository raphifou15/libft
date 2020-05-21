/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:10:26 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/15 15:51:07 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_free(char **str, int index_j)
{
	int i;

	i = 0;
	while (i <= index_j)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

static int		ft_number_word(char const *s, char c)
{
	int i;
	int number_word;

	number_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0)
		{
			while (s[i] == c)
				i++;
		}
		if ((i == 0) || (s[i - 1] == c && s[i] != c && s[i] != '\0'))
			number_word++;
		if (s[i] != '\0')
			i++;
	}
	return (number_word);
}

static char		*ft_strdup_sub(char *str, char const *s, char c)
{
	int i;
	int k_index;
	int len;

	i = 0;
	k_index = 0;
	while (s[k_index] == c)
		k_index++;
	while (s[ft_strlen(s) - 1 - i] == c)
		i++;
	len = ft_strlen(s) - (k_index + i);
	str = ft_substr(s, (unsigned int)k_index, (size_t)len);
	return (str);
}

static int		ft_set1(char **str, char *str2, char c, int i)
{
	unsigned int	k_index;
	int				j_index;
	int				turn;
	int				len;

	turn = 0;
	k_index = 0;
	j_index = 0;
	len = 0;
	while (str2[++i] != '\0')
	{
		turn++;
		if ((str2[i] == c && str2[i - 1] != c) || (str2[i + 1] == '\0'))
		{
			turn = (str2[i + 1] == '\0') ? turn + 1 : turn;
			len = turn - k_index - 1;
			if ((str[j_index] = ft_substr(str2, k_index, (size_t)len)) == NULL)
				return (ft_free(str, j_index));
			k_index = i + 1;
			j_index++;
		}
		k_index = (str2[i] == c && str2[i - 1] == c) ? k_index + 1 : k_index;
	}
	str[j_index] = NULL;
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	char	*str2;
	int		number_word;
	int		zero;

	if (s == NULL)
		return (NULL);
	str2 = NULL;
	number_word = ft_number_word(s, c);
	str = (malloc(sizeof(char *) * (number_word + 1)));
	if (str == NULL)
		return (NULL);
	if (number_word != 0)
	{
		str2 = ft_strdup_sub(str2, s, c);
		zero = ft_set1(str, str2, c, -1);
		free(str2);
		return (str) = (zero == 0) ? (NULL) : (str);
	}
	if (number_word == 0)
		str[0] = NULL;
	return (str);
}
