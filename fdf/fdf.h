/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:34:15 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/09/05 13:43:58 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <limits.h>
# include <math.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_key
{
	int		count_1;
	int		count_2;
	int		count_3;
	int		count_4;
	int		count_5;
	int		count_6;
	int		previous_1;
	int		previous_2;
}				t_key;
typedef struct s_mlx
{
	void	*mlx;
	void	*current_win;
	int		sizex;
	int		sizey;
	t_data	data;
	t_data	menu;
	t_key	key;
}				t_mlx;


int		background(t_mlx lib, t_data *data);
void	addpoint(t_mlx lib, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		random_color(void);
int	keyhandle(int keycode, t_mlx *lib);
int	arg_checker(int argc, char **argv);

#endif
