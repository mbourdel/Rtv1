/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:49:57 by mbourdel          #+#    #+#             */
/*   Updated: 2016/03/24 16:31:52 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "mlx.h"
# include "libft/libft.h"

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
# define X_SIZE 800
# define Y_SIZE 600
# define IT_MUX 43


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

typedef struct s_env	t_env;
struct					s_env
{
	t_mlx				mlx;
};

typedef struct s_sphere	t_sphere;
struct					s_sphere
{
	int					x;
	int					y;
	int					z;
	int					rayon;
};

#endif
