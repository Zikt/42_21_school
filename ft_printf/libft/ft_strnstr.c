/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:44:34 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 04:28:05 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				i;
	size_t				j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	i = ft_strlen(needle);
	while (ft_strncmp(&haystack[j], needle, i) != 0)
	{
		if (!haystack[i] || j >= (len - i))
			return (NULL);
		++j;
	}
	if (i > len)
		return (NULL);
	return ((char *)(&haystack[j]));
}
