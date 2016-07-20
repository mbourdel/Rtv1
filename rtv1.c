/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:43:37 by mbourdel          #+#    #+#             */
/*   Updated: 2016/07/20 13:48:41 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

//static double	square(double pow)
//{
//	return (pow * pow);
//}

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
	t_ray	ray;

	env->x_cursor = 0;
	env->y_cursor = 0;
	ray = create_ray(env);
	while (env->x_cursor < X_SIZE)
	{
		while (env->y_cursor < Y_SIZE)
		{	
			//touch_sphere(env, ray, env->item_list[0].sphere);
			does_it_hit(env, ray);
			ray.direction.y++;
			env->y_cursor++;
		}
		env->y_cursor = 0;
		env->x_cursor++;
		ray.direction.y = env->cam.direction.y - (Y_SIZE / 2);
		ray.direction.x++;
	}
	ft_putchar('\n');
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
