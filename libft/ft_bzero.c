/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:20:44 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 01:32:06 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		((char *)s)[i] = 0;
		i++;
		n--;
	}
}
