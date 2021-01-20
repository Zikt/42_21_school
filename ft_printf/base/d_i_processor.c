/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:43:57 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 22:16:40 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static long long	g_di;
static char			*g_num;
static int			g_pre;
static int			g_numlen;
static int			g_zeronum;
static int			g_i;

int					add_pre(void)
{
	if (g_info.flags[2] == '+' && g_di >= 0)
	{
		PRINT('+');
		return (1);
	}
	else if (g_info.flags[1] == ' ' && g_di >= 0)
	{
		PRINT(' ');
		return (1);
	}
	else if (g_di < 0)
	{
		PRINT('-');
		return (1);
	}
	return (0);
}

static void			d_i_recieve(void)
{
	if (!(ft_strcmp(g_info.length, "l")))
		g_di = va_arg(g_ap, long);
	else if (!(ft_strcmp(g_info.length, "ll")))
		g_di = va_arg(g_ap, long long);
	else if (!(ft_strcmp(g_info.length, "h")))
		g_di = (short)va_arg(g_ap, int);
	else if (!(ft_strcmp(g_info.length, "hh")))
		g_di = (char)va_arg(g_ap, int);
	else
		g_di = va_arg(g_ap, int);
	if (g_di < 0)
		g_num = ft_abs_itoa_long(-g_di);
	else
		g_num = ft_abs_itoa_long(g_di);
	g_numlen = ft_strlen(g_num);
}

static void			d_i_minflag(void)
{
	g_pre = add_pre();
	g_zeronum = g_info.precision - g_numlen;
	g_i = g_zeronum;
	if (g_zeronum < 0)
		g_zeronum = 0;
	while (g_i > 0)
	{
		PRINT('0');
		g_i--;
	}
	if (!(g_info.precision == 0 && g_di == 0))
	{
		ft_putstr(g_num);
		g_printed += g_numlen;
	}
	else
	{
		PRINT(' ');
	}
	g_i = g_info.width - (g_pre + g_zeronum + g_numlen);
	while (g_i > 0)
	{
		PRINT(' ');
		g_i--;
	}
}

static void			d_i_noflag(void)
{
	g_i = g_info.width - (g_zeronum + g_numlen);
	while (g_i > 1)
	{
		PRINT(' ');
		g_i--;
	}
	if (!add_pre() && g_i == 1)
	{
		PRINT(' ');
	}
	while (g_zeronum > 0)
	{
		PRINT('0');
		g_zeronum--;
	}
	if (!(g_info.precision == 0 && g_di == 0))
	{
		ft_putstr(g_num);
		g_printed += g_numlen;
	}
	else if (g_info.precision == 0 && g_di == 0 && g_info.width > 0)
	{
		PRINT(' ');
	}
}

void				d_i_process(void)
{
	d_i_recieve();
	if (g_info.flags[3] == '-')
		d_i_minflag();
	else if (g_info.flags[0] == '0' && g_info.precision == -1)
	{
		g_i = g_info.width - (add_pre() + g_numlen);
		while (g_i > 0)
		{
			PRINT('0');
			g_i--;
		}
		g_printed += g_numlen;
		ft_putstr(g_num);
	}
	else
	{
		g_zeronum = g_info.precision - g_numlen;
		if (g_zeronum < 0)
			g_zeronum = 0;
		d_i_noflag();
	}
	free(g_num);
}
