/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:56:59 by pgurn             #+#    #+#             */
/*   Updated: 2020/12/28 16:57:04 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char	**line);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, const char *s2);
char		*ft_strdup(const char *src);
char		*ft_strchr(const char *str, int symbol);

#endif
