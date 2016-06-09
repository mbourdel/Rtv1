/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:24:23 by mbourdel          #+#    #+#             */
/*   Updated: 2016/06/09 16:07:25 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	this_is_cam(t_env *env, int fd)
{
	int		ret;
	char	*str;

	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->cam.origin.x = ft_atof(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->cam.origin.y = ft_atof(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->cam.origin.z = ft_atof(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->cam.direction.x = ft_atof(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->cam.direction.y = ft_atof(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->cam.direction.z = ft_atof(str + 2);
	free(str);
	return (0);
}

static int	this_is_sphere(t_env *env, int fd, int *nbr)
{
	int		ret;
	char	*str;

	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->item_list[*nbr].sphere.origin.x = ft_atof(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->item_list[*nbr].sphere.origin.y = ft_atof(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->item_list[*nbr].sphere.origin.z = ft_atof(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->item_list[*nbr].sphere.radius = ft_atof(str + 2);
	free(str);
	env->item_list[*nbr++].type = 1;
	return (0);
}

static int	this_is_light(t_env *env, int fd, int *lnbr)
{
	int		ret;
	char	*str;

	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->light_list[*lnbr].origin.x = ft_atof(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->light_list[*lnbr].origin.y = ft_atof(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->light_list[*lnbr].origin.z = ft_atof(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (1);
	env->light_list[*(lnbr++)].color = (unsigned int)ft_atoi(str + 2);
	free(str);
	return (0);
}

static int	this_is_item(t_env *env, int fd, char *str, int *nbr)
{
	int		ret;

	ret = 1;
	if (ft_strcmp(str, "++sphere") == 0)
		ret = this_is_sphere(env, fd, nbr);
//	else if (ft_strcmp(str, "++cone") == 0)
//		ret = this_is_cone(env, fd, nbr);
//	else if (ft_strcmp(str, "++cylindre") == 0)
//		ret = this_is_cylindre(env, fd, nbr);
//	else if (ft_strcmp(str, "++plane") == 0)
//		ret = this_is_plane(env, fd, *nbr);
	return (ret);
}

static int	what_is_it(t_env *env, int fd, char **str, int *nbr, int *lnbr)
{
	if (**str == '&')
		env->light_nbr = ft_atoi((*str + 2));
	else if (**str == '%')
		env->item_nbr = ft_atoi((*str + 2));
	else if (**str == '=')
	{
		if (this_is_cam(env, fd))
			return (1);
	}
	else if (**str == '+')
	{
		if (this_is_item(env, fd, *str, nbr))
			return (1);
	}
	else if (**str == '-')
	{
		if (this_is_light(env, fd, lnbr))
			return (1);
	}
	free(*str);
	return (0);
}

int			parser(t_env *env, char *file_name)
{
	int		fd;
	int		ret;
	int		nbr;
	int		lnbr;
	char	*str;

	nbr = 0;
	lnbr = 0;
	fd = open(file_name, O_RDONLY);
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (*str != '/')
		{
			if (what_is_it(env, fd, &str, &nbr, &lnbr))
			{
				free(str);
				return (-1);
			}
		}
		else
			free(str);
	}
	return (ret);
}
