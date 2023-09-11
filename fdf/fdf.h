/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:34:15 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/11 12:57:48 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <limits.h>
# include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	int				x;
	int				y;
	int				value;
	struct s_map	*nx;
	struct s_map	*ny;
	struct s_map	*py;
	struct s_map	*px;
	struct s_map	*first;
}					t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*current_win;
	int		sizex;
	int		sizey;
	int		xlen;
	int		ylen;
	int		scalex;
	int		scaley;
	int		offsetx;
	int		offsety;
	double	multheight;
	double	vcos;
	double	vsin;
	double	z_angle;
	double	y_angle;
	double	x_angle;
	t_map	*map_origin;
	t_data	*data;
	t_data	*tampon;
	t_map	*map;

}				t_mlx;

int		background(t_mlx *lib, t_data *data);
int		print_logo(t_mlx *lib, t_data *data);
int		keyhandle(int keycode, t_mlx *lib);
void	addmap(t_mlx *lib, t_data *data);
int		tcolor(int red, int green, int blue);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		random_color(int value);
int		keyhandle(int keycode, t_mlx *lib);
int		arg_checker(int argc, char **argv);
void	read_map(char *filename, t_mlx *lib);
void	ft_freemap(t_mlx *lib);
void	put_dot(t_data *data, int x, int y, int color);
void	ft_freemap(t_mlx *lib);
void	reload_map(t_mlx *lib, t_data *data);
int		mouse_scroll(int button, int x, int y, t_mlx *lib);
int		closewin(t_mlx *lib);
void	line_put(t_mlx *lib, t_map *first, t_map *second, t_data *data);
t_map	*origin_map(t_map *map);

#endif
