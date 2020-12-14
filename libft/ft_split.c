/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:37:46 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 03:26:04 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_count_words(char const *s, char c)
{
	size_t				i;
	size_t				num_words;

	i = 0;
	num_words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			num_words++;
		i++;
	}
	return (num_words);
}

static size_t			ft_len_word(char const *s, char c)
{
	int					i;
	int					len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void				*ft_clear_leak(char **result, int num_words)
{
	int					i;

	i = 0;
	while (i < num_words)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static char				**ft_form_words(char const *s,
		char c, int num_words, char **result)
{
	int					i;
	int					j;
	int					len;

	i = -1;
	while (++i < num_words)
	{
		while (*s == c)
			s++;
		len = ft_len_word(s, c);
		if (!(result[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (ft_clear_leak(result, i));
		j = 0;
		while (j < len)
			result[i][j++] = *s++;
		result[i][j] = '\0';
	}
	result[i] = NULL;
	return (result);
}

char					**ft_split(char const *s, char c)
{
	char				**result;
	int					num_words;

	if (!s)
	{
		return (NULL);
	}
	num_words = ft_count_words(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (num_words + 1))))
		return (NULL);
	result = ft_form_words(s, c, num_words, result);
	return (result);
}
