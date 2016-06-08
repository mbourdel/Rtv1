/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 13:15:09 by mbourdel          #+#    #+#             */
/*   Updated: 2015/03/21 14:49:56 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char		*ft_itoa(int n)
{
	char	*res;
	size_t	int_len;

	if (n <= INT_MIN || n >= INT_MAX)
		return ((n <= INT_MIN) ? ft_strdup("INT_MIN") : ft_strdup("INT_MAX"));
	int_len = ft_intlen(n);
	res = ft_memalloc(int_len + 1);
	if (n < 0)
	{
		res[0] = '-';
		n *= (-1);
	}
	if (n < 10)
		res[--int_len] = (n + 48);
	else
	{
		while (n > 0)
		{
			res[--int_len] = ((n % 10) + 48);
			n = (n / 10);
		}
	}
	return (res);
}
