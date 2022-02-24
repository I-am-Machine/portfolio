/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:22:05 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 13:41:43 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_number_sort(t_stack *stack_a)
{
	t_list	*tmp;

	tmp = stack_a->beginning;
	if (tmp->value > tmp->next->value)
	{
		rra(stack_a);
	}
}

void	three_number_sort(t_stack *stack_a)
{
	t_list	*tmp;

	tmp = stack_a->beginning;
	index_sort(stack_a);
	if (tmp->index == 1 - 1 && tmp->next->index == 3 - 1)
	{
		sa(stack_a->beginning);
		ra(stack_a);
	}
	else if (tmp->index == 1 - 1 && tmp->next->index == 2 - 1)
	{
	}
	else if (tmp->index == 2 - 1 && tmp->next->index == 3 - 1)
		rra(stack_a);
	else if (tmp->index == 2 - 1 && tmp->next->index == 1 - 1)
		sa(stack_a->beginning);
	else if (tmp->index == 3 - 1 && tmp->next->index == 2 - 1)
	{
		sa(stack_a->beginning);
		rra(stack_a);
	}
	else if (tmp->index == 3 - 1 && tmp->next->index == 1 - 1)
		ra(stack_a);
}

void	four_number_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;

	tmp = stack_a->beginning;
	index_sort(stack_a);
	if (stack_a->end == NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		stack_a->end = tmp;
	}
	if (stack_a->beginning->index == 0)
		four_num_one(stack_a);
	else if (stack_a->beginning->index == 1)
		four_num_two(stack_a, stack_b);
	else if (stack_a->beginning->index == 2)
		four_num_three(stack_a);
	else if (stack_a->beginning->index == 3)
		four_num_four(stack_a, stack_b);
}

void	five_number_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		lowest_index;
	int		check;

	check = five_hardcode(stack_a, stack_b);
	lowest_index = find_lowest_index(stack_a);
	activate_four_num_sort(stack_a, check, lowest_index);
	index_sort(stack_a);
	if (stack_a->beginning->index == 1 - 1 \
	&& stack_a->beginning->next->index == 2 - 1 \
	&& stack_a->beginning->next->next->index == 3 - 1 \
	&& stack_a->beginning->next->next->next->index == 4 - 1 \
	&& stack_a->beginning->next->next->next->next->index == 5 - 1 \
	&& check == 0)
		index_sort(stack_a);
	else
	{
		pb(stack_a, stack_b);
		four_number_sort(stack_a, stack_b);
		pa(stack_b, stack_a);
	}	
}

void	hardcode_sort(t_stack *stack_a, t_stack *stack_b, int argc)
{
	if (argc == 3)
		two_number_sort(stack_a);
	else if (argc == 4)
		three_number_sort(stack_a);
	else if (argc == 5)
		four_number_sort(stack_a, stack_b);
	else if (argc == 6)
		five_number_sort(stack_a, stack_b);
	stack_b->beginning = NULL;
}
