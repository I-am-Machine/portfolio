/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 01:38:08 by bexner            #+#    #+#             */
/*   Updated: 2021/06/12 21:04:59 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	full_len(const char *str, char c)
{
	int	i;
	int	is_string;

	i = 0;
	is_string = 0;
	while (*str)
	{
		if (*str != c && is_string == 0)
		{
			is_string = 1;
			i++;
		}
		else if (*str == c)
			is_string = 0;
		str++;
	}
	return (i);
}

static char	*string(const char *s, int start, int end)
{
	char	*string;
	int		i;

	i = 0;
	string = (char *)malloc((end - start + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (start < end)
		string[i++] = s[start++];
	string[i] = '\0';
	return (string);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;
	char	**output;

	output = (char **)malloc((full_len(s, c) + 1) * sizeof(char *));
	if (!s || !output)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			output[j++] = string(s, start, i);
			start = -1;
		}
		i++;
	}
	output[j] = 0;
	return (output);
}
