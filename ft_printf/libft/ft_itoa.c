/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:22:01 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 19:05:38 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digit(long n)
{
	int count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int			len;
	long		num;
	char		*str;

	num = n;
	if (num == 0)
		return (ft_strdup("0"));
	len = ft_count_digit(num);
	if (num < 0)
	{
		num = num * (-1);
		len++;
	}
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	len--;
	while (num != 0)
	{
		str[len--] = (num % 10) + 48;
		num = num / 10;
	}
	if (n < 0)
		str[len] = '-';
	return (str);
}
