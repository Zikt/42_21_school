/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_processor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:23:56 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 22:13:28 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static void	c_actions(char c)
{
	size_t i;

	if (g_info.flags[3] == '-')
	{
		PRINT(c);
		i = 1;
		while (i++ < g_info.width)
		{
			PRINT(' ');
		}
		g_printed--;
	}
	else
	{
		i = 0;
		while (i++ < g_info.width - 1)
		{
			PRINT(' ');
		}
		PRINT(c);
		g_printed--;
	}
}

void		c_process(void)
{
	char c;

	c = (char)va_arg(g_ap, int);
	if (g_info.width > 1)
		c_actions(c);
	else
		PRINT(c);
}
