/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:31:19 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 02:22:32 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int						i;
	const unsigned char		*h1;
	const unsigned char		*h2;

	h1 = s1;
	h2 = s2;
	i = 0;
	while (n)
	{
		if (h1[i] == h2[i])
		{
			i++;
			n--;
		}
		else
			return (h1[i] - h2[i]);
	}
	return (0);
}
