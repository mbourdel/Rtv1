/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toutch_the_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 07:45:53 by mbourdel          #+#    #+#             */
/*   Updated: 2016/03/27 09:04:12 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	second_degree(t_env *env, t_vector ray, t_vector xzy)
{
	double		abc[3];

	abc[0] = v_dot(ray, ray);


	return (dis);
}

int		 		touch_sphere(t_env *env)
{
	t_vector	xyz;
	t_vector	ray;
	double		i;

	xyz.x = 0;
	ray.z = (double)env->item_list[0].cam.focus;

	while (xyz.x < X_SIZE)
	{
		xyz.y = 0;
		ray.x = (xyz.x - (X_SIZE / 2));
		while (xyz.y < Y_SIZE)
		{
			ray.y = (xyz.y - (Y_SIZE / 2));
			i = second_degree(env, ray, xyz);
			if (i > 0)
				touchdown(env, xyz.x, xyz.y, i);
			y++;
		}

	}

}
	vector dist = vectorSub(&r->start, &s->pos);
	float B = 2 * vectorDot(&r->dir, &dist);
	float C = vectorDot(&dist, &dist) - (s->radius * s->radius);
	float discr = B * B - 4 * A * C;
	if(discr < 0)
		retval = false;
	else{
		float sqrtdiscr = sqrtf(discr);
		float t0 = (-B + sqrtdiscr)/(2);
		float t1 = (-B - sqrtdiscr)/(2);
		if(t0 > t1)
			t0 = t1;
		if((t0 > 0.001f) && (t0 < *t)){
			*t = t0;
			retval = true;
		}else
			retval = false;
	}
	return retval;
}
