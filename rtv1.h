/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:49:57 by mbourdel          #+#    #+#             */
/*   Updated: 2016/08/16 18:35:48 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

/*
**  --key--
*/

# define ESC 53
# define ENTER 36
# define SPACE 49
# define PG_UP 116
# define PG_DW 121
# define RIGHT 124
# define LEFT 123
# define END 119
# define UP 126
# define DW 125
# define ONE 18
# define TWO 19
# define THREE 20
# define LEFT_CLK 1
# define RIGHT_CLK 2
# define SCROLL_DW 4
# define SCROLL_UP 5
# define DIST_MAX 60000

/*
**  --key end--
*/

# define X_SIZE 800
# define Y_SIZE 600
# define ITEM_MAX 10
# define LIGHT_MAX 2

typedef struct s_mlx	t_mlx;
struct					s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
};

typedef struct s_vector	t_vector;
struct					s_vector
{
	double				x;
	double				y;
	double				z;
};

typedef struct s_sphere	t_sphere;
struct					s_sphere
{
	t_vector			origin;
	double				radius;
};

typedef struct s_cylin	t_cylindre;
struct					s_cylin
{
	t_vector			origin;
	double				radius;
	int					len;
};

typedef struct s_cone	t_cone;
struct					s_cone
{
	t_vector			origin;
	double				radius;
	int					len;
};

typedef struct s_plane	t_plane;
struct					s_plane
{
	t_vector			origin;
	t_vector			direction;
};

typedef struct s_ray	t_ray;
struct					s_ray
{
	t_vector			origin;
	t_vector			direction;
};

typedef struct s_cam	t_cam;
struct					s_cam
{
	t_vector			origin;
	t_vector			direction;
	int					focus;
};

typedef struct s_item	t_item;
struct					s_item
{
	int					type;
	t_sphere			sphere;
	t_cone				cone;
	t_cylindre			cylindre;
	t_plane				plane;
};

typedef struct s_light	t_light;
struct					s_light
{
	t_vector			origin;
	unsigned int		color;
};

typedef struct s_env	t_env;
struct					s_env
{
	t_mlx				mlx;
	t_cam				cam;
	t_item				item_list[ITEM_MAX];
	t_light				light_list[LIGHT_MAX];
	int					item_nbr;
	int					light_nbr;
	int					x_cursor;
	int					y_cursor;
};

void					pixel_put_img(t_env *env, int x, int y, unsigned int color);
//int						this_is_sphere(t_env *env, int fd, int nbr);
//int						this_is_cone(t_env *env, int fd, int nbr);
//int						this_is_cylindre(t_env *env, int fd, int nbr);
//int						this_is_plane(t_env *env, int fd, int nbr);
int						touch_sphere(t_ray ray, t_sphere sphere, double *t);
double					v_dot(t_vector v1, t_vector v2);
t_vector				v_sub(t_vector v1, t_vector v2);
t_vector				v_add(t_vector v1, t_vector v2);
t_vector				v_scale(double c, t_vector v);
t_ray					create_ray(t_env *env);
//int						this_is_light(t_env *env, int fd, int nbr);
int						parser(t_env *env, char *file_name);
int						key_hook(int k, t_env *env);
int						expose_hook(t_env *env);

#endif
