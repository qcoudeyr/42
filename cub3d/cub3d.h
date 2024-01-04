/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:00:15 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/04 15:08:29 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <limits.h>
# include <math.h>

typedef struct s_utils
{
	int		i;
	int		x;
	int		y;
	int		z;
	char	c;
	char	*tmp1;
	char	*tmp2;
	char	*str1;
	char	*str2;
	char	**lst;
	char	**tab;
	void	*ptr;
	void	*ptr1;
	void	*ptr2;
	void	**lstptr;
}				t_utils;

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
	void	*c_win;
	int		sizex;
	int		sizey;
	int		xlen;
	int		ylen;
	int		scale[2];
	int		offset[2];
	char	*tx_no;
	char	*tx_so;
	char	*tx_we;
	char	*tx_ea;
	int		floor[3];
	int		ceiling[3];
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

typedef struct s_ply
{
	float	x;
	float	y;
	float	rot;
}					t_ply;

typedef struct s_cub
{
	int				fd_map;
	struct s_map	*map;
	struct s_data	data;
	struct s_mlx	*lib;
}					t_cub;
/*

//Main File Function  */
/*

//Free File Function */
int				free_struct(t_cub *t);
void			free_lib(t_mlx *lib);
void			ft_freemap(t_mlx *lib);
/*

//Init File Function  */
void			init_struct(t_cub *t);
void			lib_init(t_mlx *lib);
void			init_windows(t_mlx *lib);
/*

//Parsing File Function */
int				parse(char *str, t_mlx *lib, int x, t_map *p_x);
int				read_map(t_cub *t, t_mlx *lib);
/*

//Map File Function */
int				check_error_map(t_map *map);
void			addmap(t_mlx *lib, t_data *data);
t_map			*origin_map(t_map *map);
t_map			*create_map_ptn(int x, int y, int value);
void			map_addelement(t_map **first, t_map **p_x, t_map **p_e, t_map *map);
/*

//Windows File Function  */
int	closewin(t_mlx *lib);
/*

//Rendering File Function */
int				tcolor(int red, int green, int blue);
void			pixel_put(t_data *data, int x, int y, int color);
void			sqr_print(t_data *data, int	len[2], int offset[2], int color);
void			dspl_map(t_mlx *lib, t_map *map);
/*

//Utils File Function */
int				keyhandle(int keycode, t_mlx *lib);
int				mouse_scroll(int button, int x, int y, t_mlx *lib);
void			utils_init(t_utils *u);
/*

//Error File Function */
int				printerr(char *str);
int				printerrf(char *str, void *ptr);
// Text colors
# define CL_BLACK   "\033[30m"
# define CL_RED     "\033[31m"
# define CL_GREEN   "\033[32m"
# define CL_YELLOW  "\033[33m"
# define CL_BLUE    "\033[34m"
# define CL_MAGENTA "\033[35m"
# define CL_CYAN    "\033[36m"
# define CL_WHITE   "\033[37m"

// Background colors
# define BG_BLACK   "\033[40m"
# define BG_RED     "\033[41m"
# define BG_GREEN   "\033[42m"
# define BG_YELLOW  "\033[43m"
# define BG_BLUE    "\033[44m"
# define BG_MAGENTA "\033[45m"
# define BG_CYAN    "\033[46m"
# define BG_WHITE   "\033[47m"

// Text attributes
# define RESET     "\033[0m"
# define BOLD      "\033[1m"
# define DIM       "\033[2m"
# define UNDERLINE "\033[4m"
# define BLINK     "\033[5m"
# define REVERSE   "\033[7m"
# define HIDDEN    "\033[8m"

#endif
