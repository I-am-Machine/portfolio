/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 03:07:52 by bexner            #+#    #+#             */
/*   Updated: 2022/02/23 00:46:12 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *mew)
{
	if (mew->map[mew->player_y - 1][mew->player_x] == '0' \
	|| mew->map[mew->player_y - 1][mew->player_x] == 'C')
	{
		if (mew->map[mew->player_y - 1][mew->player_x] == 'C')
			mew->collectible_count = mew->collectible_count - 1;
		mew->player_x = mew->player_x;
		mew->player_y = mew->player_y - 1;
		mew->map[mew->player_y + 1][mew->player_x] = '0';
		mew->map[mew->player_y][mew->player_x] = 'P';
		mew->counted = mew->counted + 1;
	}
	else if ((mew->map[mew->player_y - 1][mew->player_x] == 'E' \
	&& mew->collectible_count == 0) \
	|| mew->map[mew->player_y - 1][mew->player_x] == 'K')
	{
		mew->map[mew->player_y][mew->player_x] = '0';
		create_mewmap_load_imgs(*mew);
		usleep(1000000);
		exit_game(mew);
	}	
}

void	move_down(t_data *mew)
{
	if (mew->map[mew->player_y + 1][mew->player_x] == '0' \
	|| mew->map[mew->player_y + 1][mew->player_x] == 'C')
	{
		if (mew->map[mew->player_y + 1][mew->player_x] == 'C')
			mew->collectible_count = mew->collectible_count - 1;
		mew->map[mew->player_y][mew->player_x] = '0';
		mew->player_x = mew->player_x;
		mew->player_y = mew->player_y + 1;
		mew->map[mew->player_y][mew->player_x] = 'P';
		mew->counted = mew->counted + 1;
	}
	else if ((mew->map[mew->player_y + 1][mew->player_x] == 'E' \
	&& mew->collectible_count == 0) \
	|| mew->map[mew->player_y + 1][mew->player_x] == 'K')
	{
		mew->map[mew->player_y][mew->player_x] = '0';
		usleep(1000000);
		exit_game(mew);
	}	
}

void	move_left(t_data *mew)
{
	if (mew->map[mew->player_y][mew->player_x - 1] == '0' \
	|| mew->map[mew->player_y][mew->player_x - 1] == 'C')
	{
		if (mew->map[mew->player_y][mew->player_x - 1] == 'C')
			mew->collectible_count = mew->collectible_count - 1;
		mew->map[mew->player_y][mew->player_x] = '0';
		mew->player_x = mew->player_x - 1;
		mew->player_y = mew->player_y;
		mew->map[mew->player_y][mew->player_x] = 'P';
		mew->counted = mew->counted + 1;
	}
	else if ((mew->map[mew->player_y][mew->player_x - 1] == 'E' \
	&& mew->collectible_count == 0) \
	|| mew->map[mew->player_y][mew->player_x - 1] == 'K')
	{
		mew->map[mew->player_y][mew->player_x] = '0';
		usleep(1000000);
		exit_game(mew);
	}
}

void	move_right(t_data *mew)
{
	if (mew->map[mew->player_y][mew->player_x + 1] == '0' \
	|| mew->map[mew->player_y][mew->player_x + 1] == 'C')
	{
		if (mew->map[mew->player_y][mew->player_x + 1] == 'C')
			mew->collectible_count = mew->collectible_count - 1;
		mew->map[mew->player_y][mew->player_x] = '0';
		mew->player_x = mew->player_x + 1;
		mew->player_y = mew->player_y;
		mew->map[mew->player_y][mew->player_x] = 'P';
		mew->counted = mew->counted + 1;
	}
	else if ((mew->map[mew->player_y][mew->player_x + 1] == 'E' \
	&& mew->collectible_count == 0) \
	|| mew->map[mew->player_y][mew->player_x + 1] == 'K')
	{
		mew->map[mew->player_y][mew->player_x] = '0';
		usleep(1000000);
		exit_game(mew);
	}	
}

void	move_player(int key, t_data *mew)
{
	if (key == UP)
		move_up(mew);
	if (key == DOWN)
		move_down(mew);
	if (key == LEFT)
		move_left(mew);
	if (key == RIGHT)
		move_right(mew);
	return ;
}
