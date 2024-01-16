/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 08:56:38 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/16 16:25:59 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_freemap(t_mlx *lib)
{
	t_map	*current;
	t_map	*next_x;
	t_map	*next_y;
	t_map	*temp;

	if (lib->map_origin != NULL)
		current = origin_map(lib->map_origin);
	else
		current = lib->map_origin;
	while (current != NULL)
	{
		next_x = current->nx;
		next_y = current->ny;
		free(current);
		current = next_x;
		while (next_y != NULL)
		{
			temp = next_y;
			next_y = next_y->ny;
			temp = pfree(temp);
		}
	}
	lib->map = NULL;
}

void	free_text(t_mlx *lib, t_tex *t)
{
	(void)lib;
	if (t->fname != NULL)
		t->fname = pfree(t->fname);
	if (t->ptr != NULL)
		t->ptr = pfree(t->ptr);
}

void	free_lib(t_mlx *lib)
{
	ft_freemap(lib);
	free_text(lib, &lib->no);
	free_text(lib, &lib->so);
	free_text(lib, &lib->we);
	free_text(lib, &lib->ea);
	lib->mlx = pfree(lib->mlx);
	lib->data = pfree(lib->data);
	lib->tampon = pfree(lib->tampon);
	lib = pfree(lib);
}

void	free_wmap(t_cub *t)
{
	int	y;

	y = 0;
	while(y <= t->lib->ylen)
	{
		t->wmap[y] = pfree(t->wmap[y]);
		y++;
	}
	t->wmap = pfree(t->wmap);
}

int	free_struct(t_cub *t)
{
	free_wmap(t);
	free_lib(t->lib);
	t->ply = pfree(t->ply);
	t->rdr = pfree(t->rdr);
	t = pfree(t);
	return (0);
}
