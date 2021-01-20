/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:32:10 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 22:21:13 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	add_flags(char **f, int *i)
{
	(*i)++;
	while (1)
	{
		if ((*f)[(*i)] == '0')
			g_info.flags[0] = (*f)[(*i)];
		else if ((*f)[(*i)] == ' ')
			g_info.flags[1] = (*f)[(*i)];
		else if ((*f)[(*i)] == '+')
			g_info.flags[2] = (*f)[(*i)];
		else if ((*f)[(*i)] == '-')
			g_info.flags[3] = (*f)[(*i)];
		else if ((*f)[(*i)] == '#')
			g_info.flags[4] = (*f)[(*i)];
		else
			break ;
		(*i)++;
	}
}

void	add_width(char **f, int *i)
{
	if ((g_info.width = ft_atoi(&((*f)[(*i)]))))
		while ('0' <= (*f)[(*i)] && (*f)[(*i)] <= '9')
			(*i)++;
	else if ((*f)[(*i)] == '*')
	{
		g_info.width = va_arg(g_ap, int);
		(*i)++;
	}
}

void	add_precision(char **f, int *i)
{
	if ((*f)[(*i)] == '.')
	{
		(*i)++;
		if ((g_info.precision = ft_atoi(&((*f)[(*i)]))))
			while ('0' <= (*f)[(*i)] && (*f)[(*i)] <= '9')
				(*i)++;
		else if ((*f)[(*i)] == '*')
		{
			g_info.precision = va_arg(g_ap, int);
			(*i)++;
		}
		else if ((*f)[(*i)] == '0')
		{
			g_info.precision = 0;
			(*i)++;
		}
		else
			g_info.precision = 0;
	}
}

void	add_length(char **f, int *i)
{
	if ((*f)[(*i)] == 'L')
	{
		g_info.length[0] = 'L';
		(*i)++;
	}
	else if ((*f)[(*i)] == 'l')
	{
		g_info.length[0] = 'l';
		if ((*f)[(*i) + 1] == 'l')
		{
			g_info.length[1] = 'l';
			(*i)++;
		}
		(*i)++;
	}
	else if ((*f)[(*i)] == 'h')
	{
		g_info.length[0] = 'h';
		if ((*f)[(*i) + 1] == 'h')
		{
			g_info.length[1] = 'h';
			(*i)++;
		}
		(*i)++;
	}
}
