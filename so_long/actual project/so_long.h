/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:46:01 by bexner            #+#    #+#             */
/*   Updated: 2022/03/28 13:56:11 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include <stdio.h>

# ifdef __linux__
#  define UP 119
#  define DOWN 115
#  define RIGHT 97
#  define LEFT 100
#  define ESC 65307
# elif __APPLE__
#  define UP 119
#  define DOWN 115
#  define RIGHT 100
#  define LEFT 97
#  define ESC 65307
# endif

typedef struct t_player_data_mlx {
	int		x;
	int		y;
	int		exit_count;
	int		player_count;
	int		collectible_count;
	int		player_x;
	int		player_y;
	int		counted;
	int		rows;
	int		columns;
	void	*mlx;
	void	*window;
	void	*img;
	char	**map;
}			t_data;

void	create_mewmap_load_imgs(t_data mew);
void	move_player(int key, t_data *mew);
void	move_down(t_data *mew);
void	move_left(t_data *mew);
void	move_right(t_data *mew);
void	move_up(t_data *mew);
int		load_map(t_data *mew, char **argv);
size_t	count_to_new_line(const char *str);
int		check_mewmap(t_data *mew);
int		loop_map(t_data *mew);
int		wall_check(t_data mew);
int		movement_count(t_data *mew);
int		keyboard(int key, t_data *mew);
int		exit_game(t_data *mew);
void	put_floor_img(t_data mew, int x, int y);
void	put_wall_img(t_data mew, int x, int y);
void	put_collectible_img(t_data mew, int x, int y);
void	put_player_img(t_data mew, int x, int y);
void	put_enemy_img(t_data mew, int x, int y);
int		line_len(t_data *mew, char *line, int index, int i);

#endif
