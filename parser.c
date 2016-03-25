/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:24:23 by mbourdel          #+#    #+#             */
/*   Updated: 2016/03/25 14:33:12 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	what_is_it(t_env *env, int fd, char *str)
{
	if (*str == '&')
		env->light_nbr = ft_atoi(str);
	else if (*str == '%')
		env->item_nbr = ft_atoi(str);
	else if (

int			parser(t_env *env, char *file_name)
{
	int		fd;
	char	*str;

	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &str))
	{
		if (*str != '/')
			what_is_it(env, fd, str);
		else
			free(str);
	}
	return (0);
}
