/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:39:05 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 01:29:07 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	long long	result;
	int			i;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i++] == '-');
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result > 214748365) || (result == 214748365 && str[i] - '0' > 7))
		{
			if (sign == 1)
				return (2147483647);
			else
				return (-2147483648);
		}
		result = (result * 10) + str[i++] - 48;
	}
	return (result * sign);
}
