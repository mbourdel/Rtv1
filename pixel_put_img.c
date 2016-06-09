/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:35:32 by mbourdel          #+#    #+#             */
/*   Updated: 2016/06/08 17:49:05 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		pixel_put_img(t_env *env, int x, int y, unsigned int color)
{
	int		i;
	char	clr[(env->mlx.bpp / 8) - 1];

	if (!(x >= X_SIZE || y >= Y_SIZE) && x >= 0 && y>= 0)
	{
		i = 0;
		while (i < (env->mlx.bpp / 8) - 1)
		{
			clr[i] = color >> (i * 8);
			i++;
		}
		env->mlx.data[(y * env->mlx.size_line) +
			(x * (env->mlx.bpp / 8)) + i] = 0;
		i--;
		while (i >= 0)
		{
			env->mlx.data[(y * env->mlx.size_line) +
				(x * (env->mlx.bpp / 8)) + i] = clr[i];
			i--;
		}
	}
}
