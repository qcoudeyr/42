/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:11:14 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2024/01/18 17:34:17 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_texture_path(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_calloc(1000, sizeof(char));
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

int	get_color(t_cub *t, char *str, int s)
{
	char	**temp;
	char	*value;
	int		i;

	value = get_texture_path(str);
	temp = ft_split(value, ',');
	if (temp[3] != NULL || (temp[2] == NULL || *temp[2] == 0))
	{
		tabfree((void **)temp);
		return (printerrf("Error !\nColor are not correct !\n", value));
	}
	value = pfree(value);
	i = -1;
	if (s == 1)
	{
		while (i++ < 2)
			t->lib->floor[i] = ft_atoi(temp[i]);
	}
	else
	{
		while (i++ < 2)
			t->lib->ceiling[i] = ft_atoi(temp[i]);
	}
	temp = tabfree((void **)temp);
	return (0);
}

void	set_player_empty(t_cub *t, t_utils *u)
{
	if (t->wmap[u->y][u->x] >= 2 && t->wmap[u->y][u->x] <= 5)
	{
		t->ply->posy = u->x;
		t->ply->posx = u->y;
		t->wmap[u->y][u->x] = 0;
	}
}

void	set_player_direction(t_cub *t, t_utils *u)
{
	if (t->wmap[u->y][u->x] == 2)
	{
		t->ply->dirx = -1.00;
		t->ply->planey = 0.66;
	}
	else if (t->wmap[u->y][u->x] == 3)
	{
		t->ply->dirx = 1.00;
		t->ply->planey = -0.66;
	}
	else if (t->wmap[u->y][u->x] == 4)
	{
		t->ply->diry = 1.00;
		t->ply->planex = 0.66;
	}
	else if (t->wmap[u->y][u->x] == 5)
	{
		t->ply->diry = -1.00;
		t->ply->planex = -0.66;
	}
	set_player_empty(t, u);
}

void	get_ply_pos(t_cub *t)
{
	t_utils	*u;

	u = ft_calloc(1, sizeof(t_utils));
	utils_init(u);
	while (u->y < t->lib->ylen)
	{
		u->x = 0;
		while (u->x < t->lib->xlen)
		{
			set_player_direction(t, u);
			u->x++;
		}
		u->y++;
	}
	u = pfree(u);
}
