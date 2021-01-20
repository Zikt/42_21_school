/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:51:14 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 22:22:34 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static int g_i;

void		ft_clear(void)
{
	ft_bzero(g_info.flags, sizeof(char) * 5);
	g_info.width = 0;
	g_info.precision = -1;
	ft_bzero(g_info.length, 3);
	g_info.arg_type = 0;
}

void		ft_parser(char **f)
{
	ft_clear();
	add_flags(f, &g_i);
	add_width(f, &g_i);
	add_precision(f, &g_i);
	add_length(f, &g_i);
	if ((*f)[g_i] == 'c' || (*f)[g_i] == 's' || (*f)[g_i] == 'p' ||
		(*f)[g_i] == 'd' || (*f)[g_i] == 'i' || (*f)[g_i] == 'o' ||
		(*f)[g_i] == 'u' || (*f)[g_i] == 'x' || (*f)[g_i] == 'X' ||
		(*f)[g_i] == 'f' || (*f)[g_i] == '%')
	{
		g_info.arg_type = (*f)[g_i];
		g_i++;
	}
	(g_info.arg_type == 'c') ? c_process() : 0;
	(g_info.arg_type == 's') ? s_process() : 0;
	(g_info.arg_type == 'p') ? p_process() : 0;
	(g_info.arg_type == 'd' || g_info.arg_type == 'i') ? d_i_process() : 0;
	(g_info.arg_type == 'o') ? o_process() : 0;
	(g_info.arg_type == 'u') ? u_process() : 0;
	(g_info.arg_type == 'x') ? x_process(0) : 0;
	(g_info.arg_type == 'X') ? x_process(1) : 0;
	(g_info.arg_type == 'f') ? f_process() : 0;
	(g_info.arg_type == '%') ? proc_process() : 0;
}

int			ft_printf(const char *s, ...)
{
	char	*f;

	f = (char*)s;
	va_start(g_ap, s);
	g_printed = 0;
	g_i = 0;
	while (f[g_i] != '\0')
	{
		if (f[g_i] == '%')
			ft_parser(&f);
		else
		{
			ft_putchar(f[g_i++]);
			g_printed++;
		}
	}
	va_end(g_ap);
	return (g_printed);
}
