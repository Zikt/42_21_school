/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:05:29 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 04:33:27 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	int		n;
	char	*trim;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	n = ft_strlen(s1);
	j = n;
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	while (ft_strchr(set, s1[j]) && j > 0)
		j--;
	len = j - i + 1;
	trim = ft_substr(s1, i, len);
	return (trim);
}
