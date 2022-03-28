/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:05:12 by bexner            #+#    #+#             */
/*   Updated: 2021/10/25 18:17:17 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*push_leftovers_into_buf(char *buffer)
{
	char	*next_line_start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer)
		return (0);
	while (buffer && buffer[i] != '\n')
		i++;
	i++;
	next_line_start = (char *) ft_calloc ((ft_strlen(buffer) - i + 1),
			sizeof(char));
	while (buffer[i] != '\0')
	{
		next_line_start[j] = buffer[i];
		i++;
		j++;
	}
	next_line_start[j] = 0;
	return (next_line_start);
}

char	*create_new_buffer(int ret, char *buffer)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ret == BUFFER_SIZE || (ft_strchr(buffer, '\n') != 0))
	{
		tmp = push_leftovers_into_buf(buffer);
		while (i <= BUFFER_SIZE)
		{
			buffer[i] = 0;
			i++;
		}
		ft_memmove(buffer, tmp, ft_strlen(tmp));
		free (tmp);
	}
	else
	{		
		while (i <= BUFFER_SIZE)
		{
			buffer[i] = 0;
			i++;
		}
	}
	return (buffer);
}

char	*join_n_free_str(char *current_line, char *buffer)
{
	char	*joined_str;

	joined_str = ft_strjoin(current_line, buffer);
	free (current_line);
	return (joined_str);
}

char	*return_line(int ret, int fd, char *buffer, char *current_line)
{
	if (buffer[0] != '\0')
		current_line = join_n_free_str(current_line, buffer);
	if (ft_strchr(current_line, '\n') == 0)
	{
		while ((ft_strchr(buffer, '\n') == 0) && (ret == BUFFER_SIZE))
		{	
			ret = read(fd, buffer, BUFFER_SIZE);
			if (buffer[0] == '\0')
			{
				free (current_line);
				return (0);
			}
			buffer[ret] = '\0';
			current_line = join_n_free_str(current_line, buffer);
		}
	}
	buffer = create_new_buffer(ret, buffer);
	if ((buffer[0] == '\0') && (current_line[0] == '\0'))
	{
		free (current_line);
		return (0);
	}
	return (current_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*current_line;
	int			ret;

	if (fd < 0
		|| BUFFER_SIZE <= 0
		|| read(fd, NULL, 0) < 0)
		return (0);
	ret = BUFFER_SIZE;
	current_line = (char *)ft_calloc(1, sizeof(char));
	return (return_line(ret, fd, buffer, current_line));
}
