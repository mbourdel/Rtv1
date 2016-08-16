/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:47:26 by mbourdel          #+#    #+#             */
/*   Updated: 2016/08/16 17:35:29 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray		create_ray(t_env *env)
{
	t_ray	ray;

	ray.origin.x = env->cam.origin.x;
	ray.origin.y = env->cam.origin.y;
	ray.origin.z = env->cam.origin.z;
	ray.direction.x = env->cam.direction.x - X_SIZE / 2;
	ray.direction.y = env->cam.direction.y - Y_SIZE / 2;
	ray.direction.z = env->cam.direction.z;
	return (ray);
}

static void	print_ray(t_env *env, t_ray ray, int i, double len)
{
	pixel_put_img(env, env->x_cursor, env->y_cursor, 0x00FF00);
	if (i != 0)
		if (len == 0 && ray.origin.x == 0)
			ft_putchar('x');
}

void		does_it_hit(t_env *env, t_ray ray)
{
	double		t[env->item_nbr];
	double		len;
	int			hit[env->item_nbr];
	int			i;			

	i = 0;
	len = DIST_MAX;
	while (i < env->item_nbr)
	{
		if (env->item_list[i].type == 1)
			hit[i] = touch_sphere(ray, env->item_list[i].sphere, &t[i]);
		else if (env->item_list[i].type == 2)
			hit[i] = touch_plan(ray, env->item_list[i].plane, &t[i]);
		if (t[i] < len && hit[i] == 1)
			len = t[i];
		i++;
	}
	i = 0;
	if (len < DIST_MAX)
	{
		while (t[i] != len)
			i++;
		print_ray(env, ray, i, len);
	}
}
