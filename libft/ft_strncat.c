/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:02:02 by tlaukkan          #+#    #+#             */
/*   Updated: 2019/10/23 17:01:57 by tlaukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t l;

	i = 0;
	l = 0;
	while (s1[i])
		i++;
	while (s2[l] && l < n)
	{
		s1[i] = s2[l];
		i++;
		l++;
	}
	s1[i] = '\0';
	return (s1);
}
