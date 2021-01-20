/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_processor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:08:57 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 22:24:02 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static unsigned long long	g_o;
static char					*g_num;
static int					g_numlen;
static int					g_zeronum;
static int					g_n;

static void					o_minflag2(void)
{
	if (!(g_info.precision == 0 && g_o == 0))
	{
		ft_putstr(g_num);
		g_printed += g_numlen;
	}
	else
	{
		PRINT(' ');
	}
	g_n = g_info.width - (g_zeronum + g_numlen);
	while (g_n > 0)
	{
		PRINT(' ');
		g_n--;
	}
}

static void					o_minflag(void)
{
	g_zeronum = g_info.precision - g_numlen;
	if (g_zeronum > 0)
	{
		g_n = g_zeronum;
		while (g_n > 0)
		{
			PRINT('0');
			g_n--;
		}
	}
	else if (g_info.flags[4] == '#' && g_o)
	{
		PRINT('0');
		g_zeronum = 1;
	}
	else
		g_zeronum = 0;
	o_minflag2();
}

static void					o_zeroflag(void)
{
	g_zeronum = g_info.width - g_numlen;
	if (g_zeronum > 0)
		while (g_zeronum > 0)
		{
			PRINT('0');
			g_zeronum--;
		}
	else if (g_info.flags[4] == '#' && g_o)
	{
		PRINT('0');
	}
	ft_putstr(g_num);
	g_printed += g_numlen;
}

static void					o_noflag(void)
{
	if (g_info.precision > g_numlen)
		g_zeronum = g_info.precision - g_numlen;
	else if (g_info.flags[4] == '#' && g_o)
		g_zeronum = 1;
	else
		g_zeronum = 0;
	g_n = g_info.width - (g_zeronum + g_numlen);
	while (g_n-- > 0)
	{
		PRINT(' ');
	}
	while (g_zeronum > 0)
	{
		PRINT('0');
		g_zeronum--;
	}
	if (!(g_info.precision == 0 && g_o == 0))
	{
		g_printed += g_numlen;
		ft_putstr(g_num);
	}
	else
	{
		PRINT(' ');
	}
}

void						o_process(void)
{
	ulong_init(&g_o);
	if (!g_o && !g_info.precision && !g_info.width)
	{
		if (g_info.flags[4] == '#')
		{
			PRINT('0');
		}
		return ;
	}
	in_octave(&g_num, g_o);
	g_numlen = ft_strlen(g_num);
	if (g_info.flags[3] == '-')
		o_minflag();
	else if (g_info.flags[0] == '0' && g_info.precision == -1)
		o_zeroflag();
	else
		o_noflag();
	free(g_num);
}
