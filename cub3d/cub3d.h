/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:00:15 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/19 12:02:01 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <limits.h>
# include <math.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_utils
{
	int		i;
	int		x;
	int		y;
	int		z;
	int		v[2];
	int		color;
	int		offset[2];
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

typedef struct s_tex
{
	char	*fname;
	int		w;
	int		h;
	t_data	*ptr;
}			t_tex;

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
	int		floor[3];
	int		ceiling[3];
	double	multheight;
	double	vcos;
	double	vsin;
	double	z_angle;
	double	y_angle;
	double	x_angle;
	t_tex	no;
	t_tex	so;
	t_tex	we;
	t_tex	ea;
	t_map	*map_origin;
	t_data	*data;
	t_data	*tampon;
	t_map	*map;

}			t_mlx;

typedef struct s_rend
{
	unsigned int	color;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			step;
	double			texpos;
	double			wallx;
	int				texy;
	int				mapx;
	int				mapy;
	int				stepx;
	int				texx;
	int				stepy;
	int				hit;
	int				lineheight;
	int				side;
	int				drawstart;
	int				drawend;
	int				x;
	int				y;
}				t_rdr;

typedef struct s_arrow
{
	double		x;
	double		y;
	int			size;
	int			color;
}				t_arrow;

typedef struct s_ply
{
	int		is_set;
	int		**wmap;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	olddirx;
	double	oldplanex;
	double	mspeed;
	double	rspeed;
}				t_ply;

typedef struct s_cub
{
	int				fd_map;
	int				texw;
	int				texh;
	int				**wmap;
	double			test;
	double			init_t;
	struct s_map	*map;
	struct s_data	data;
	struct s_mlx	*lib;
	struct s_ply	*ply;
	struct s_rend	*rdr;
}				t_cub;
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
int				get_texture(t_mlx *lib);
int				get_color(t_cub *t, char *str, int s);
int				set_player_empty(t_cub *t, t_utils *u);
int				get_ply_pos(t_cub *t);
char			*get_texture_path(char *str);
void			set_player_direction(t_cub *t, t_utils *u);
/*

//Map File Function */
int				check_error_map(t_cub *t);
int				get_map(t_cub *t, char *str);
int				map_value(char c);
void			addmap(t_mlx *lib, t_data *data);
void			map_addelement(t_map **first, t_map **p_x, \
t_map **p_e, t_map *map);
t_map			*origin_map(t_map *map);
t_map			*create_map_ptn(int x, int y, int value);
/*

//Windows File Function  */
int				closewin(t_mlx *lib);
void			print_background(t_cub *t);
void			sqr_print(t_data *data, int len[2], int offset[2], int color);
void			dspl_map(t_cub *t, t_mlx *lib);

/*

//Rendering File Function */
int				render(t_cub *t);
int				color(int red, int green, int blue);
void			pixel_put(t_data *data, int x, int y, int color);
void			draw_arrow(t_data *data, t_cub *t);
void			texture_put(t_cub *t, int x, int y, unsigned int color);
void			texture_calcul(t_cub *t);
void			check_hit_wall(t_cub *t);
void			raydir_calcul(t_cub *t);
void			draw_texture(t_cub *t);
void			check_side(t_cub *t);
unsigned int	get_pixel(t_data *data, int x, int y);
/*

//Utils File Function */
int				keyhandle(int keycode, t_cub *t);
int				mouse_scroll(int button, int x, int y, t_mlx *lib);
int				check_color(int color);
void			utils_init(t_utils *u);
void			get_new_image(t_mlx *lib);
int				trgb(int t, int r, int g, int b);
double			ft_abs(double i);
t_utils			*utils_free(t_utils *u);
unsigned long	getticks(t_cub *t);
/*

//PLayer Movement File Function */
void			ply_mv_lft(t_ply *p);
void			ply_mv_fwd(t_ply *p);
void			ply_mv_bwd(t_ply *p);
void			ply_mv_rgt(t_ply *p);
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
