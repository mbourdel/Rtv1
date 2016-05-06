/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:24:23 by mbourdel          #+#    #+#             */
/*   Updated: 2016/05/06 12:20:34 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	this_is_cam(t_env *env, int fd)
{
	int		ret;
	char	*str;

	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (-1);
	env->cam.origin.x = ft_atod(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (-1);
	env->cam.origin.y = ft_atod(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (-1);
	env->cam.origin.z = ft_atod(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (-1);
	env->cam.direction.x = ft_atod(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (-1);
	env->cam.direction.y = ft_atod(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (-1);
	env->cam.direction.z = ft_atod(str + 2);
	free(str);
	if ((ret = get_next_line(fd, &str)) == -1 || ret == 0)
		return (-1);
	env->cam.focus = ft_atoi(str + 2);
	free(str);
	return (1);
}

static int	this_is_item(t_env *env, int fd, char *str, int nbr)
{
	int		ret;

	if (ft_strcmp(str, "++sphere") == 0)
		ret = this_is_sphere(env, fd, nbr);
	else if (ft_strcmp(str, "++cone") == 0)
		ret = this_is_cone(env, fd, nbr);
	else if (ft_strcmp(str, "++cylindre") == 0)
		ret = this_is_cylindre(env, fd, nbr);
	else if (ft_strcmp(str, "++plane") == 0)
		ret = this_is_plane(env, fd, nbr);
	return (ret);
}

static int	what_is_it(t_env *env, int fd, char **str, int nbr)
{
	if (**str == '&')
		env->light_nbr = ft_atoi((*str + 2));
	else if (**str == '%')
		env->item_nbr = ft_atoi((*str + 2));
	else if (**str == '=')
	{
		if (1 != this_is_cam(env, fd, nbr))
			return (1);
	}
	else if (**str == '+')
	{
		if (1 != this_is_item(env, fd, *str, nbr))
			return (1);
	}
/*	else if (**str == '-')
	{
		if (1 != this_is_light(env, fd, nbr))
			return (1);
	}*/
	free(*str);
	return (0);
}

int			parser(t_env *env, char *file_name)
{
	int		fd;
	int		ret;
	int		nbr;
	char	*str;

	nbr = -2;
	fd = open(file_name, O_RDONLY);
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (*str != '/')
		{
			if (what_is_it(env, fd, &str, nbr++))
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
