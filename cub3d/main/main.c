/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:59:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/24 20:29:53 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_arg(int argc, char **argv, t_cub *t)
{
	char *temp;

	if (argc > 2)
	{
		ft_printf(CL_RED BOLD"Error, Too many args !\nUsage: ./cub3D map.cub\n"RESET);
		return (-1);
	}
	else if (argc == 1)
	{
		ft_printf("No map entered, do you want to load the default one ? \nY/N $>");
		temp = get_next_line(0);
		if ((!temp && !(*temp)) || ft_strrchr("yY", *temp) == 0)
		{
			ft_printf\
(CL_RED BOLD"Error, no map entered !\nUsage: ./cub3D map.cub\n"RESET);
			temp = pfree(temp);
			return (-1);
		}
		else if (ft_strrchr("yY", *temp) != 0)
			t->fd_map = open("../map/default.cub", O_RDONLY);
		temp = pfree(temp);
	}
	else if (argc == 2)
	{
		if (ft_strnstr(""))
		t->fd_map = open(argv[1], O_RDONLY);
	}
	return (0);
}

void	init_struct(t_cub *t)
{
	t->fd_map = 0;
}

int	main(int argc, char **argv)
{
// init var
	t_cub	*t;

	t = ft_calloc(1, sizeof(t_cub));
	init_struct(t);
// check arg before init
	if (check_arg(argc, argv, t) != 0)
		return (0);

}
