/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:22:11 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 04:08:30 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char			*d;
	const char		*s;
	size_t			n;
	size_t			dl;

	d = dst;
	s = src;
	n = dstsize;
	while (n-- != 0 && *d != '\0')
		d++;
	dl = d - dst;
	n = dstsize - dl;
	if (n == 0)
		return (dl + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dl + (s - src));
}
