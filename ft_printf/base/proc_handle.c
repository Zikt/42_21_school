/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:43:36 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 22:25:51 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static void	proc_noflag(void)
{
	int i;

	i = g_info.width - 1;
	while (i > 0)
	{
		if (g_info.flags[0] == '0')
			ft_putchar('0');
		else
			ft_putchar(' ');
		g_printed++;
		i--;
	}
	PRINT('%');
}

void		proc_process(void)
{
	int i;

	if (g_info.flags[3] == '-')
	{
		PRINT('%');
		i = g_info.width - 1;
		while (i > 0)
		{
			PRINT(' ');
			i--;
		}
	}
	else
		proc_noflag();
}
