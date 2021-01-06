/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:56:39 by pgurn             #+#    #+#             */
/*   Updated: 2020/12/28 16:56:43 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_remainder(char **remainder, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (*remainder)
	{
		if ((p_n = ft_strchr(*remainder, '\n')))
		{
			*p_n = '\0';
			*line = *remainder;
			*remainder = ft_strdup(++p_n);
		}
		else
		{
			*line = *remainder;
			*remainder = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (p_n);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	int				count;
	char			*p_n;
	static char		*remainder;

	buf = 0;
	if ((fd < 0 || !line || BUFFER_SIZE < 1)
	|| (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1)))
	|| (read(fd, buf, 0) == -1)))
		return (-1);
	p_n = check_remainder(&remainder, line);
	while (!p_n && (count = read(fd, buf, BUFFER_SIZE)))
	{
		buf[count] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			if (!(remainder = ft_strdup(++p_n)))
				return (-1);
		}
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
	}
	free(buf);
	return ((count || p_n) ? 1 : 0);
}
