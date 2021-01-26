/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:04:52 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/25 20:17:35 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(uintmax_t n)
{
	char		*str;
	int			num_len;

	num_len = ft_uintlen(n);
	if (!(str = ft_calloc((num_len + 1), sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
