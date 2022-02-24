/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 03:25:08 by bexner            #+#    #+#             */
/*   Updated: 2022/02/23 00:44:48 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_to_new_line(const char *str)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			x++;
		i++;
	}
	i = i - x;
	return (i);
}

int	load_map(t_data *mew, char **argv)
{
	int		i;
	int		index;
	char	*line;
	int		fd;

	i = 0;
	index = 0;
	fd = open(argv[1], O_RDONLY);
	while (i < mew->columns)
	{
		mew->map[i] = (char *)ft_calloc(mew->rows + 1, sizeof(char *));
		line = get_next_line(fd);
		mew->rows = count_to_new_line(line);
		while (index < mew->rows)
		{
			mew->map[i][index] = line[index];
			index++;
		}
		index = 0;
		if ((int)count_to_new_line(line) != mew->rows)
			return (1);
		i++;
	}
	close(fd);
	return (0);
}

int	wall_check(t_data mew)
{
	int	i;

	i = 0;
	while (i < mew.rows)
	{
		if ((mew.map[0][i] != '1' || mew.map[mew.columns - 1][i] != '1'))
		{
			write(1, "Er666, the mew->map is not surronded by Walls.", 42);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < mew.columns)
	{
		if (mew.map[i][0] != '1' || mew.map[i][mew.rows - 1] != '1')
		{
			write(1, "Err9r, the mew->map is not surronded by Walls.", 42);
			return (1);
		}
		i++;
	}
	return (0);
}

void	loop_map(t_data *mew)
{
	while (mew->y < mew->columns)
	{
		while (mew->map[mew->y][mew->x] != '\0')
		{
			if (mew->map[mew->y][mew->x] == 'P')
			{
				mew->player_count++;
				mew->player_y = mew->y;
				mew->player_x = mew->x;
			}	
			if (mew->map[mew->y][mew->x] == 'C')
				mew->collectible_count++;
			if (mew->map[mew->y][mew->x] == 'E')
				mew->exit_count++;
			mew->x++;
		}
		mew->x = 0;
		mew->y++;
	}
}

int	check_mewmap(t_data *mew)
{
	mew->x = 0;
	mew->y = 0;
	mew->player_count = 0;
	mew->exit_count = 0;
	if (wall_check(*mew) != 0)
	{
		write(1, "Error, Map is not surrounded by Walls.", 39);
		return (0);
	}
	while (mew->y < mew->columns)
	{
		loop_map(mew);
		mew->x = 0;
		mew->y++;
	}
	if (mew->player_count != 1 || mew->collectible_count == 0 \
	|| mew->exit_count == 0)
		return (0);
	return (mew->collectible_count);
}
