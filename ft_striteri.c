/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 10:29:38 by rkhelif           #+#    #+#             */
/*   Updated: 2020/05/05 11:03:14 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*)){
    int i;

    i = 0;
    if (s == NULL) return ;
    if (f == NULL) return ;
    while (s[i] != '\0'){
        f(i, &s[i]);
        i++;
    }
}