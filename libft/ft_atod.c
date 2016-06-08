/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 22:30:14 by mbourdel          #+#    #+#             */
/*   Updated: 2016/03/26 23:39:37 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atod(const char *str)
{
	double	sign;
	double	res;
	double	flt;

	while (ft_isblank(*str))
		str++;
	res = 0.0;
	sign = 1.0;
	flt = 0.1;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-' ? -1.0 : 1.0);
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = (res * 10.0) + (*str - '0');
		str++;
	}
	while (ft_isdigit(*(++str)))
	{
		res += ((*str - '0') * flt);
		flt *= 0.1;
	}
	return (res * sign);
}

float		ft_atof(const char *str)
{
	float	sign;
	float	res;
	float	flt;

	while (ft_isblank(*str))
		str++;
	res = 0.0;
	sign = 1.0;
	flt = 0.1;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-' ? -1.0 : 1.0);
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = (res * 10.0) + (*str - '0');
		str++;
	}
	while (ft_isdigit(*(++str)))
	{
		res += ((*str - '0') * flt);
		flt *= 0.1;
	}
	return (res * sign);
}
