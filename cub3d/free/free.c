/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 08:56:38 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/29 17:10:35 by  qcoudeyr        ###   ########.fr       */
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

void	free_lib(t_mlx *lib)
{
	ft_freemap(lib);
	lib->mlx = pfree(lib->mlx);
	lib->data = pfree(lib->data);
	lib->tx_no = pfree(lib->tx_no);
	lib->tx_so = pfree(lib->tx_so);
	lib->tx_we = pfree(lib->tx_we);
	lib->tx_ea = pfree(lib->tx_ea);
	lib->tampon = pfree(lib->tampon);
	lib = pfree(lib);
}

int	free_struct(t_cub *t)
{
	free_lib(t->lib);
	t = pfree(t);
	return (0);
}
