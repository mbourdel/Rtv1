/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 01:19:34 by mbourdel          #+#    #+#             */
/*   Updated: 2016/03/27 06:05:20 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				this_is_sphere(t_env *env, int fd, int nbr)
{
	int			ret;
	char		*str;

	env->item_list[nbr].type = 1;
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (-1);
	env->item_list[nbr].sphere.origin.x = ft_atod(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (-1);
	env->item_list[nbr].sphere.origin.y = ft_atod(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (-1);
	env->item_list[nbr].sphere.origin.z = ft_atod(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (-1);
	env->item_list[nbr].sphere.radius = ft_atod(str + 2);
	free(str);
	return (ret);
}

int				this_is_cone(t_env *env, int fd, int nbr)
{
	int			ret;
	t_cone		cone;

	return (ret);
}

int				this_is_cylindre(t_env *env, int fd, int nbr)
{
	int			ret;
	t_cylindre	cylindre;

	return (ret);
}

int				this_is_plane(t_env *enc, int fd, int nbr)
{
	int			ret;
	t_plane		plane;

	return (ret);
}
