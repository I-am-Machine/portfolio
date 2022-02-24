/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 03:48:13 by bexner            #+#    #+#             */
/*   Updated: 2022/01/23 04:22:26 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement_count(t_data *mew)
{
	char	*counter_string;

	counter_string = ft_itoa(mew->counted);
	mlx_string_put(mew->mlx, mew->window, 10, 20, 0x000000, \
	counter_string);
	free(counter_string);
	return (mew->counted);
}

int	keyboard(int key, t_data *mew)
{
	if (key == ESC)
	{
		exit_game(mew);
	}
	if (key == UP || key == LEFT || key == DOWN || key == RIGHT)
	{
		move_player(key, mew);
		create_mewmap_load_imgs(*mew);
	}
	return (0);
}

int	exit_game(t_data *mew)
{
	mlx_destroy_window(mew->mlx, mew->window);
	exit(0);
}
