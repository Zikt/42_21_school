/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:55:02 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/25 19:55:12 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	intmax_t	num;
	int			i;
	char		*tab;

	i = 0;
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	tab = ft_itoa_base(num, base_to);
	return (tab);
}
