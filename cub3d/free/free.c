/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 08:56:38 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/10 15:43:09 by  qcoudeyr        ###   ########.fr       */
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

void	free_text(t_tex *t)
{
	if (t->fname != NULL)
		t->fname = pfree(t->fname);
	if (t->ptr != NULL)
		t->ptr = pfree(t->ptr);
}

void	free_lib(t_mlx *lib)
{
	ft_freemap(lib);
	lib->mlx = pfree(lib->mlx);
	lib->data = pfree(lib->data);
	free_text(&lib->no);
	free_text(&lib->so);
	free_text(&lib->we);
	free_text(&lib->ea);
	lib->tampon = pfree(lib->tampon);
	lib = pfree(lib);
}

int	free_struct(t_cub *t)
{
	free_lib(t->lib);
	t = pfree(t);
	return (0);
}
