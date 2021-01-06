/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:57:43 by pgurn             #+#    #+#             */
/*   Updated: 2020/12/28 16:57:46 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr(const char *str, int symbol)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == symbol)
			return ((char*)&str[i]);
		i++;
	}
	if (symbol == '\0')
		return ((char*)&str[i]);
	return (NULL);
}

char		*ft_strdup(const char *src)
{
	int			i;
	int			len;
	char		*str;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (src && (i < len))
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, const char *s2)
{
	size_t		i;
	char		*cat_s;

	i = 0;
	if (!(s1 && s2))
		return (NULL);
	if (!(cat_s = (char*)malloc(sizeof(char) *
		(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		cat_s[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		cat_s[i] = *s2++;
		i++;
	}
	cat_s[i] = '\0';
	return (cat_s);
}
