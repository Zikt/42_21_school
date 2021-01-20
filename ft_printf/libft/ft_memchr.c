/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:01:41 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 02:14:56 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	c1;
	unsigned char	*h1;

	c1 = (unsigned char)c;
	h1 = (unsigned char *)s;
	i = 0;
	while (n)
	{
		if (h1[i] == c1)
		{
			return (&h1[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}
