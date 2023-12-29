/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  qcoudeyr <@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:59:42 by  qcoudeyr         #+#    #+#             */
/*   Updated: 2023/12/29 14:39:55 by  qcoudeyr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_nomap(t_cub *t)
{
	char	*temp;

	printerr("No map entered, do you want to load the default one ? \nY/N $>");
	temp = get_next_line(0);
	get_next_line(-1);
	if ((!temp && !(*temp)) || ft_strrchr("yY", *temp) == 0)
	{
		temp = pfree(temp);
		return (printerr("Error, no map entered !\nUsage: ./cub3D map.cub\n"));
	}
	else if (ft_strrchr("yY", *temp) != 0)
		t->fd_map = open("./map/default.cub", O_RDONLY);
	temp = pfree(temp);
	if (t->fd_map < 0)
	{
		perror("open");
		return (-1);
	}
	else
		return (0);
}

int	check_arg(int argc, char **argv, t_cub *t)
{
	if (argc > 2)
		return (printerr("Error, Too many args !\nUsage: ./cub3D map.cub\n"));
	else if (argc == 1)
		return (handle_nomap(t));
	else if (argc == 2)
	{
		if (!ft_strnstr((argv[1] + (ft_strlen(argv[1]) - 4)), ".cub", 4))
			return \
	(printerr("Error, Wrong format map entered !\nUsage: ./cub3D map.cub\n"));
		else
		{
			t->fd_map = open(argv[1], O_RDONLY);
			if (t->fd_map < 0)
			{
				perror("open");
				return (-1);
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	*t;

	t = ft_calloc(1, sizeof(t_cub));
	init_struct(t);
	if (check_arg(argc, argv, t) != 0)
		return (free_struct(t));
	read_map(t, argv[1], t->lib); // need to modify the parsing to follow the new rules
	if (t->lib->map == NULL)
		return (free_struct(t));
	t->lib->mlx = mlx_init();
	init_windows(t->lib);
	mlx_mouse_hook(t->lib->current_win, mouse_scroll, t->lib);
	mlx_hook(t->lib->current_win, 2, 1L << 0, keyhandle, t->lib);
	mlx_hook(t->lib->current_win, 17, 0, closewin, t->lib);
	mlx_loop(t->lib->mlx);
	mlx_destroy_window(t->lib->mlx, t->lib->current_win);
	mlx_destroy_display(t->lib->mlx);
	free_struct(t);
	return (0);
}
