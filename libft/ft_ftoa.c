/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:03:16 by mbourdel          #+#    #+#             */
/*   Updated: 2015/04/10 11:40:50 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ftoa(float nbr)
{
	int			entire;
	float		floating;
	char		*res;
	char		*tmp1;
	char		*tmp2;

	entire = (int)nbr;
	floating = nbr - (float)entire;
	while (floating != (int)floating)
		floating *= 10;
	tmp1 = ft_itoa(entire);
	tmp2 = ft_strjoin(tmp1, ".");
	free(tmp1);
	tmp1 = ft_itoa((int)floating);
	res = ft_strjoin(tmp2, tmp1);
	free(tmp1);
	free(tmp2);
	return (res);
}
