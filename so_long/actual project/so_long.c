/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:17:47 by bexner            #+#    #+#             */
/*   Updated: 2022/03/27 18:37:37 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_exit_img(t_data mew, int x, int y)
{
	char	*exit_path_name;
	void	*img;
	int		size;

	size = 100;
	exit_path_name = "assets/exit.xpm";
	img = mlx_xpm_file_to_image(mew.mlx, exit_path_name, &size, &size);
	mlx_put_image_to_window(mew.mlx, mew.window, img, x * 100, y * 100);
}

void	init_mew_variables(t_data *mew)
{
	mew->columns = 0;
	mew->rows = 0;
	mew->counted = 0;
	mew->collectible_count = 0;
}

int	init_variables(t_data *mew, char **argv)
{
	char	*line;
	int		fd;

	init_mew_variables(mew);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (fd <= 0)
		return (0);
	while (line != 0)
	{
		line = get_next_line(fd);
		mew->columns++;
	}
	close(fd);
	mew->map = (char **)malloc((mew->columns + 1) * sizeof(char *));
	if (load_map(mew, argv) != 0)
	{
		write(1, "Error, Map could not be loaded.\n", 33);
		return (-1);
	}
	mew->collectible_count = check_mewmap(mew);
	if (mew->collectible_count < 1)
		return (-1);
	return (0);
}

void	create_mewmap_load_imgs(t_data mew)
{
	mew.x = 0;
	mew.y = 0;
	while (mew.map[mew.y])
	{
		while (mew.map[mew.y][mew.x])
		{
			put_floor_img(mew, mew.x, mew.y);
			if (mew.map[mew.y][mew.x] == 'P')
				put_player_img(mew, mew.x, mew.y);
			if (mew.map[mew.y][mew.x] == '1')
				put_wall_img(mew, mew.x, mew.y);
			if (mew.map[mew.y][mew.x] == 'E')
				put_exit_img(mew, mew.x, mew.y);
			if (mew.map[mew.y][mew.x] == 'C')
				put_collectible_img(mew, mew.x, mew.y);
			if (mew.map[mew.y][mew.x] == 'K')
				put_enemy_img(mew, mew.x, mew.y);
			mew.x++;
		}
		mew.x = 0;
		mew.y++;
	}
}

int	main(int argc, char **argv)
{
	t_data		mew;

	if (argc != 2)
	{
		write(1, "Try Run ./so_long map.ber\n", 27);
		return (-2);
	}
	if (init_variables(&mew, argv) != 0)
	{
		write(1, "Try Run ./so_long map.ber2\n", 28);
		return (-1);
	}
	mew.mlx = mlx_init();
	mew.window = mlx_new_window(mew.mlx, mew.rows * 100, \
	mew.columns * 100, "so_long");
	create_mewmap_load_imgs(mew);
	mlx_key_hook(mew.window, keyboard, (void *) &mew);
	mlx_hook(mew.window, 17, 1L << 17, exit_game, &mew);
	mlx_loop_hook(mew.mlx, movement_count, (void *) &mew);
	mlx_loop(mew.mlx);
	return (0);
}
