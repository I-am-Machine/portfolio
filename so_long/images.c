/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 03:16:36 by bexner            #+#    #+#             */
/*   Updated: 2022/01/23 16:20:37 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor_img(t_data mew, int x, int y)
{
	char	*floor_path_name;
	void	*img;
	int		size;

	size = 100;
	floor_path_name = "assets/floor.xpm";
	img = mlx_xpm_file_to_image(mew.mlx, floor_path_name, &size, &size);
	mlx_put_image_to_window(mew.mlx, mew.window, img, x * 100, y * 100);
}

void	put_enemy_img(t_data mew, int x, int y)
{
	char	*enemy_path_name;
	void	*img;
	int		size;

	size = 100;
	enemy_path_name = "assets/enemy.xpm";
	img = mlx_xpm_file_to_image(mew.mlx, enemy_path_name, &size, &size);
	mlx_put_image_to_window(mew.mlx, mew.window, img, x * 100, y * 100);
}

void	put_collectible_img(t_data mew, int x, int y)
{
	char	*collectible_path_name;
	void	*img;
	int		size;

	size = 100;
	collectible_path_name = "assets/collectible.xpm";
	img = mlx_xpm_file_to_image(mew.mlx, collectible_path_name, &size, &size);
	mlx_put_image_to_window(mew.mlx, mew.window, img, x * 100, y * 100);
}

void	put_wall_img(t_data mew, int x, int y)
{
	char	*wall_path_name;
	void	*img;
	int		size;

	size = 100;
	wall_path_name = "assets/wall.xpm";
	img = mlx_xpm_file_to_image(mew.mlx, wall_path_name, &size, &size);
	mlx_put_image_to_window(mew.mlx, mew.window, img, x * 100, y * 100);
}

void	put_player_img(t_data mew, int x, int y)
{
	char	*player_path_name;
	void	*img;
	int		size;

	size = 100;
	player_path_name = "assets/player.xpm";
	img = mlx_xpm_file_to_image(mew.mlx, player_path_name, &size, &size);
	mlx_put_image_to_window(mew.mlx, mew.window, img, x * 100, y * 100);
}
