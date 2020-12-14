/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:47:25 by pgurn             #+#    #+#             */
/*   Updated: 2020/11/24 04:22:05 by pgurn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*h1;
	unsigned char	*h2;

	i = 0;
	h1 = (unsigned char *)s1;
	h2 = (unsigned char *)s2;
	while ((h1[i] || h2[i]) && (i < n))
	{
		if (h1[i] != h2[i])
		{
			return (h1[i] - h2[i]);
		}
		i++;
	}
	return (0);
}
