/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:47:26 by mbourdel          #+#    #+#             */
/*   Updated: 2016/05/06 12:13:35 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray		create_ray(t_env *env)
{
	t_ray	ray;

	ray.origin.x = env->cam.origin.x;
	ray.origin.y = env->cam.origin.y;
	ray.origin.z = env->cam.origin.z;
	ray.direction.x = env->cam.direction.x;
	ray.direction.y = env->cam.direction.x;
	ray.direction.z = env->cam.direction.z;
	return (ray);
}

void		does_it_hit(t_env *env, t_ray ray)
{
	if (touch_sphere(t_ray, env->item_list[1].sphere))
		yes_it_hurt(toto);
	
}
