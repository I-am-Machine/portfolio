/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:05:12 by bexner            #+#    #+#             */
/*   Updated: 2022/01/23 16:25:08 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "so_long.h"

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 11

# endif

# ifndef MAX_FD

#  define MAX_FD 1024

# endif

char	*get_next_line(int fd);
char	*gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
size_t	slen(const char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
void	*ft_gnl_memcpy(void *dst, const void *src, size_t n);
void	*ft_gnl_memmove(void *dst, const void *src, size_t len);
void	*ft_gnl_malloc(size_t count, size_t size);
char	*ft_gnl_prepare_string(int fd, int bytes_read, \
char	*rtn_str, char **tmpstr);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif