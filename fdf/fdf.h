/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:34:15 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/05/17 10:30:27 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <limits.h>
# include <math.h>

typedef struct mlx
{
	void	*ptr;
	void	*win;
	int		mouse_x;
	int		mouse_y;
}	t_mlx;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		win_h;
	int		win_w;
	int		scale;
}	t_data;

typedef struct coord
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct coord	*next;
}	t_coord;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	drawLine(t_data *data, int x0, int y0, int x1, int y1);

#endif
