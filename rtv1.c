/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:43:37 by mbourdel          #+#    #+#             */
/*   Updated: 2016/03/27 09:04:54 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	square(double pow)
{
	return (pow * pow);
}

int			key_hook(int k, t_env *env)
{
	if (k == ESC)
	{
		free(env->mlx.data);
		free(env->mlx.img);
		free(env->mlx.win);
		free(env->mlx.mlx);
		exit(0);
	}
	return (0);
}

int			expose_hook(t_env *env)
{
	double	vx;
	double	vy;
	double	vz;
	double	a, b, c;

	vz = (double)env->item_list[0].cam.focus;
	while (x < X_SIZE)
	{
		vx = (x - (X_SIZE / 2));
		while (y < Y_SIZE)
		{
			vy = (y - (Y_SIZE / 2));
			a = vx * vx + vy * vy + vz * vz;
			b = 2 * vx * (x - env->item_list[1].sphere.origin.x);
			c =  square(x - env->item_list[1].sphere.origin.x);

			b += 2 * vy * (y - env->item_list[1].sphere.origin.y);
			c += square(y - env->item_list[1].sphere.origin.y);

			b += 2 * vz * (vz-env->item_list[1].sphere.origin.z);
			c += square(vz - env->item_list[1].sphere.origin.z);
			c -= square(env->item_list[1].sphere.origin.radius);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac != 2 || (parser(&env, av[1])) == -1)
	{
		ft_putendl("Invalid argument or an error occured during reading");
		return (1);
	}
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
