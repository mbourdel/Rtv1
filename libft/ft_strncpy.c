/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:32:35 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/02 18:03:40 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		strlen;
	size_t		i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	strlen = ft_strlen((char*)src);
	while (i < n)
	{
		if (i > strlen)
			dest[i] = '\0';
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
