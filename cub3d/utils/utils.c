/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:48:20 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/26 17:44:44 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	keyhandle(int keycode, t_mlx *lib)
{
	if (keycode == 65307)
		return (closewin(lib));
	else
	{
		if (keycode == 65364)
			lib->offsetx += 10;
		if (keycode == 65362)
			lib->offsetx -= 10;
		if (keycode == 65363)
			lib->offsety += 10;
		if (keycode == 65361)
			lib->offsety -= 10;
	}
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_mlx *lib)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		if (lib->scalex > 2 && lib->scaley > 2)
		{
			lib->scalex = 0.90 * (double)lib->scalex;
			lib->scaley = 0.90 * (double)lib->scaley;
		}
	}
	else if (button == 5)
	{
		if (lib->scalex < 10 && lib->scaley < 10)
		{
			lib->scalex += 1;
			lib->scaley += 1;
		}
		else
		{
			lib->scalex = 1.2 * (double)lib->scalex;
			lib->scaley = 1.2 * (double)lib->scaley;
		}
	}
	return (0);
}
