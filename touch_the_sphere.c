/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_the_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 07:45:53 by mbourdel          #+#    #+#             */
/*   Updated: 2016/06/10 18:06:08 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
static void		touchdown(t_env *env, t_ray ray, float t)
{
	pixel_put_img(env, (int)ray.origin.x, (int)ray.origin.y, 0xFFFFFF - t);
}
*/

static void		touchdown(t_env *env,/* t_ray ray,*/ double t)
{
	unsigned int	color;
	unsigned char	change;
	unsigned char	little_t;

	t /= 4;
	little_t = (int)t;
	change = 0xFF;
	//change = little_t & change;
//	ft_putchar(change);
//	ft_putchar('\n');
	color = 0xFFFF00;
	color = change | color >> 8;
	color = ~little_t;
	color = 0xFFFF00;
	pixel_put_img(env, env->x_cursor, env->y_cursor, color);
	return ;
}

static double	second_degree(t_ray ray, t_sphere s)
{
	t_vector	abc;
	t_vector	dist;
	double		t0;
	double		t1;
	double		i;

	abc.x = v_dot(ray.direction, ray.direction);
	dist = v_sub(ray.origin, s.origin);
	abc.y = 2 * v_dot(ray.origin, dist);
	abc.z = v_dot(dist, dist) - (s.radius * s.radius);
	i = abc.y * abc.y - 4 * abc.x * abc.z;
	if (i < 0)
		return (-1);
	i = sqrt(i);
	t0 = ((abc.y * -1) + i) / 2;
	t1 = ((abc.y * -1) - i) / 2;
	return (t0 > t1 ? t1 : t0);
}

int		 		touch_sphere(t_env *env, t_ray ray, t_sphere sphere)
{
	double		t;

	t = second_degree(ray, sphere);
	if (t >= 0)
		touchdown(env, /*ray,*/ t);
	return (0);
}
