/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:48:20 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/04 10:43:24 by  qcoudeyr        ###   ########.fr       */
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

t_utils	*utils_init(void)
{
	t_utils	*u;
	u = ft_calloc(1, sizeof(t_utils));

	u->i = 0;
	u->x = 0;
	u->y = 0;
	u->z = 0;
	u->c = 0;
	u->tmp1 = NULL;
	u->tmp2 = NULL;
	u->str1 = NULL;
	u->str2 = NULL;
	u->lst = NULL;
	u->tab = NULL;
	u->ptr = NULL;
	u->ptr1 = NULL;
	u->ptr2 = NULL;
	u->lstptr = NULL;
	return (u);
}

t_utils	*utils_free(t_utils *u)
{

	u->i = 0;
	u->x = 0;
	u->y = 0;
	u->z = 0;
	u->c = 0;
	if (u->tmp1 != NULL)
		u->tmp1 = pfree(u->tmp1);
	if (u->tmp2 != NULL)
		u->tmp2 = pfree(u->tmp2);
	if (u->str1 != NULL)
		u->str1 = pfree(u->str1);
	if (u->str2 != NULL)
		u->str2 = pfree(u->str2);
	if (u->lst != NULL)
		u->lst = pfree(u->lst);
	if (u->tab != NULL)
		u->tab = tabfree((void **)u->tab);
	if (u->ptr != NULL)
		u->ptr = pfree(u->ptr);
	if (u->ptr1 != NULL)
		u->ptr1 = pfree();
	if (u->ptr2 != NULL)
		u->ptr2 = pfree();
	if (u->lstptr != NULL)
		u->lstptr = tabfree(u->lstptr);
	return (u);
}
