/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_processor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:18:19 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 22:26:55 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static void	s_minflag(char *s)
{
	int i;
	int a;

	if (g_info.precision == 0)
		return ;
	else if (g_info.precision > 0)
		a = ft_strnlen(s, g_info.precision);
	else
		a = ft_strlen(s);
	ft_putnstr(s, g_info.precision);
	g_printed += a;
	i = g_info.width - a;
	while (i > 0)
	{
		PRINT(' ');
		i--;
	}
}

static void	s_noflag(char *s)
{
	int i;
	int a;

	if (g_info.precision == 0)
		return ;
	else if (g_info.precision > 0)
		a = ft_strnlen(s, g_info.precision);
	else
		a = ft_strlen(s);
	g_printed += a;
	i = g_info.width - a;
	while (i > 0)
	{
		PRINT(' ');
		i--;
	}
	ft_putnstr(s, g_info.precision);
}

void		s_process(void)
{
	char	*s;

	s = va_arg(g_ap, char*);
	if (!s)
	{
		ft_putstr("(null)");
		g_printed += 6;
		return ;
	}
	if (g_info.flags[3] == '-')
		s_minflag(s);
	else
		s_noflag(s);
}
