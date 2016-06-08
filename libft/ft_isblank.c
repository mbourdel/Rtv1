/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 23:25:03 by mbourdel          #+#    #+#             */
/*   Updated: 2016/03/26 23:27:19 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isblank(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
			|| c == '\f')
		return (1);
	return (0);
}