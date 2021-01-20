/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:52:15 by pgurn             #+#    #+#             */
/*   Updated: 2021/01/20 22:46:57 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_info
{
	char		flags[5];
	size_t		width;
	int			prec;
	char		length[3];
	char		type;
}				t_info;

t_info			g_info;
va_list			g_ap;
int				g_printed;

# define PRINT(x) ft_putchar(x); g_printed++;
# define ALLOC(x, y, z) if(!(x = (y)malloc(z))) {ft_putendl("ERROR"); exit(0);}
# define ALLOC_SIZE 60

/*
**==========================printf Main fn Start============================
*/
int				ft_printf(const char *s, ...);
void			ft_parser(char **f);
void			proc_process(void);
void			c_process(void);
void			s_process(void);
void			p_process(void);
void			d_i_process(void);
void			o_process(void);
void			u_process(void);
void			x_process(int var);
void			f_process(void);
char			*ft_abs_itoa_long(unsigned long long n);
void			add_flags(char **f, int *i);
void			add_width(char **f, int *i);
void			add_precision(char **f, int *i);
void			add_length(char **f, int *i);
void			in_double(char **num, long double f);
void			ulong_init(unsigned long long *a);
void			in_octave(char **dec, unsigned long long o);
void			x_minflag(unsigned long long x, int var, int numlen, char *num);
void			x_zeroflag(unsigned long long x,
							int var, int numlen, char *num);
void			x_noflag(unsigned long long x, int var, int numlen, char *num);
/*
**==========================printf Main fn End==============================
*/
#endif
