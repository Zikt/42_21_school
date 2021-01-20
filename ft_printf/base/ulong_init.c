/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulong_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:58:43 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 22:28:35 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ulong_init(unsigned long long *a)
{
	if (!(ft_strcmp(g_info.length, "l")))
		*a = va_arg(g_ap, unsigned long);
	else if (!(ft_strcmp(g_info.length, "ll")))
		*a = va_arg(g_ap, unsigned long long);
	else if (!(ft_strcmp(g_info.length, "h")))
		*a = (unsigned short)va_arg(g_ap, unsigned int);
	else if (!(ft_strcmp(g_info.length, "hh")))
		*a = (unsigned char)va_arg(g_ap, unsigned int);
	else
		*a = va_arg(g_ap, unsigned int);
}
