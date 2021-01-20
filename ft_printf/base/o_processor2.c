/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_processor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:18:53 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 20:13:41 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static int	oct_cnt(unsigned long long o)
{
	int i;

	i = 1;
	while (o /= 8)
		i++;
	return (i);
}

void		in_octave(char **dec, unsigned long long o)
{
	int len;
	int i;

	len = oct_cnt(o);
	ALLOC(*dec, char*, sizeof(char) * (len + 1));
	(*dec)[len] = '\0';
	i = len - 1;
	while (o / 8)
	{
		(*dec)[i] = o % 8 + '0';
		o /= 8;
		i--;
	}
	(*dec)[i] = o % 8 + '0';
}
