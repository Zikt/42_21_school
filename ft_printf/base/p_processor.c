/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_processor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:28:46 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 22:25:04 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

static void	address_hex(void *p0, char **addr)
{
	int			i;
	int			j;
	long long	p;

	p = (long long)p0;
	if (!p0)
	{
		*addr = ft_strjoin("", "0x0");
		g_printed += 3;
		return ;
	}
	ALLOC(*addr, char*, sizeof(char) * 15);
	(*addr)[14] = '\0';
	(*addr)[0] = '0';
	(*addr)[1] = 'x';
	g_printed += 2;
	i = ((sizeof(p) << 3) - 4 * 5);
	j = 2;
	while (j < 14)
	{
		g_printed++;
		(*addr)[j] = hex_digit((p >> i) & 0xf);
		i -= 4;
		j++;
	}
}

static void	p_print(char *addr)
{
	int i;

	i = g_info.width - ft_strlen(addr);
	if (g_info.flags[3] == '-')
	{
		ft_putstr(addr);
		while (i > 0)
		{
			PRINT(' ');
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			PRINT(' ');
			i--;
		}
		ft_putstr(addr);
	}
}

void		p_process(void)
{
	void	*p;
	char	*addr;

	p = va_arg(g_ap, void*);
	address_hex(p, &addr);
	if (g_info.width > ft_strlen(addr))
		p_print(addr);
	else
		ft_putstr(addr);
	free(addr);
}
