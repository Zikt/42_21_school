/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:53:17 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/25 20:17:51 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoi_base(char *str, char *base)
{
	int			i;
	intmax_t	atoi;
	int			negative;
	int			base_len;

	i = 0;
	atoi = 0;
	negative = 0;
	base_len = ft_strlen(base);
	if (!ft_check_base(base))
		return (0);
	while (ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = 1;
		str++;
	}
	while (ft_is_in_stri(*str, base) >= 0)
	{
		atoi = atoi * base_len + ft_is_in_stri(*str, base);
		str++;
	}
	return (negative ? -atoi : atoi);
}
