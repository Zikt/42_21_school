/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:13:49 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 02:26:28 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*h1;
	unsigned char	*h2;

	i = 0;
	h1 = (unsigned char *)src;
	h2 = (unsigned char *)dst;
	if (h1 || h2)
	{
		while (n)
		{
			h2[i] = h1[i];
			i++;
			n--;
		}
		return (dst);
	}
	return (dst);
}
