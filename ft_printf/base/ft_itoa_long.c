/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:06:13 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 20:13:06 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static size_t	ft_cnt(unsigned long long n)
{
	size_t i;

	i = 0;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_abs_itoa_long(unsigned long long n)
{
	char	*str;
	size_t	len;

	len = 2 + ft_cnt(n);
	ALLOC(str, char*, len);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
