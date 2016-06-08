/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:06:18 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/02 17:55:35 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	if (!s)
		return (NULL);
	str = (unsigned char*)s;
	while (str[i] != d && i < (n - 1))
		i++;
	if (str[i] == d && n != 0)
		return (str += i);
	return (NULL);
}
