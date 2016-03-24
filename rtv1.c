/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:43:37 by mbourdel          #+#    #+#             */
/*   Updated: 2016/03/24 16:34:58 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			key_hook(int k, t_env *env)
{
	if (k == ESC)
	{
		free(env->mlx.data);
		mlx_destroy_image(env->mlx.mlx, env->mlx.img);
		mlx_destroy_window(env->mlx.mlx, env->mlx.win);
		free(env->mlx.mlx);
		exit(0);
	}
	return (0);
}

int			expose_hook(t_env *env)
{
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	env;

	env.mlx.mlx = mlx_init();
	env.mlx.win = mlx_new_window(env.mlx.mlx, X_SIZE, Y_SIZE, "Rtv1");
	env.mlx.img = mlx_new_image(env.mlx.mlx, X_SIZE, Y_SIZE);
	env.mlx.data = mlx_get_data_addr(env.mlx.img, &(env.mlx.bpp),
		&(env.mlx.size_line), &(env.mlx.endian));
	mlx_expose_hook(env.mlx.win, expose_hook, &env);
	mlx_key_hook(env.mlx.win, key_hook, &env);
	mlx_loop(env.mlx.mlx);
	return (0);
}
