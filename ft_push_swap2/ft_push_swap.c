/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:47:14 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 23:01:32 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew2(int valueinput)
{
	t_list	*output;

	output = (t_list *) malloc(sizeof(t_list));
	output -> value = valueinput;
	output -> next = NULL;
	output -> previous = NULL;
	return (output);
}

int	number_of_elements(t_list *a_stack)
{
	t_list	*tmp;
	int		number_of_elements;

	number_of_elements = 1;
	tmp = a_stack;
	while (tmp->next != NULL)
	{
		number_of_elements++;
		tmp = tmp->next;
	}
	return (number_of_elements);
}

int	input_check2(char **argv, int x, int y)
{
	while (argv[y][x])
	{
		if ((ft_isdigit(argv[y][x]) == 1 && argv[y][x] != '\n') \
		&& (argv[y][x] != '-' && ft_isdigit(argv[y][x + 1]) == 1) && \
		(argv[y][x] != ' ' && ft_isdigit(argv[y][x + 1]) == 1))
			return (1);
		x++;
	}
	return (0);
}

int	input_check(int argc, char **argv, int x, int y)
{
	int	y2;

	y2 = 1;
	while (argv[y])
	{
		if (ft_atoi2(argv[y]) > 2147483647 \
		|| (ft_atoi2(argv[y]) < -2147483648 && ft_atoi2(argv[y]) < 0))
			return (1);
		while (y2 < argc - 1)
		{
			if (ft_atoi2(argv[y2]) == ft_atoi2(argv[y]) && y2 != y)
				return (1);
			y2++;
		}
		y2 = 1;
		if (input_check2(argv, x, y) == 1)
			return (1);
		y++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (input_check(argc, argv, 0, 1) == 1 || argc <= 2)
		return (1);
	stack_a = (t_stack *) malloc(sizeof(t_stack));
	stack_b = (t_stack *) malloc(sizeof(t_stack));
	stack_a->beginning = NULL;
	stack_a->end = NULL;
	stack_b->beginning = NULL;
	stack_b->end = NULL;
	create_a_stack(stack_a->beginning, stack_a, argv);
	if (argc >= 3 && argc < 7)
		hardcode_sort(stack_a, stack_b, argc);
	else
	{
		index_sort(stack_a);
		ft_radix(stack_a, stack_b, number_of_elements(stack_a->beginning));
	}
	free_all(stack_a, stack_b);
	return (argc);
}
