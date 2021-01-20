/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:02:01 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 02:36:01 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*h1;
	unsigned char		*h2;

	i = 0;
	h1 = (unsigned char *)src;
	h2 = (unsigned char *)dst;
	if (len == 0 || dst == src)
		return (dst);
	if (h1 < h2)
		while (++i <= len)
			h2[len - i] = h1[len - i];
	else
		while (len-- > 0)
			*(h2++) = *(h1++);
	return (dst);
}
