/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_num_one_and_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:47:47 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 13:34:55 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	four_num_one2(t_stack *stack_a)
{
	if (stack_a->beginning->index == 1 - 1 \
	&& stack_a->beginning->next->index == 4 - 1 \
	&& stack_a->beginning->next->next->index == 2 - 1)
	{
		sa(stack_a->beginning);
		ra(stack_a);
	}
	else if (stack_a->beginning->index == 1 - 1 \
	&& stack_a->beginning->next->index == 3 - 1 \
	&& stack_a->beginning->next->next->index == 4 - 1)
	{
		rra(stack_a);
		sa(stack_a->beginning);
	}
	else if (stack_a->beginning->index == 1 - 1 \
	&& stack_a->beginning->next->index == 2 - 1 \
	&& stack_a->beginning->next->next->index == 4 - 1)
	{
		rra(stack_a);
		rra(stack_a);
		sa(stack_a->beginning);
		ra(stack_a);
		ra(stack_a);
	}
}

void	four_num_one(t_stack *stack_a)
{
	index_sort(stack_a);
	if (stack_a->beginning->index == 1 - 1 \
	&& stack_a->beginning->next->index == 3 - 1 \
	&& stack_a->beginning->next->next->index == 2 - 1)
	{
		sa(stack_a->beginning);
		rra(stack_a);
		sa(stack_a->beginning);
		ra(stack_a);
		ra(stack_a);
	}
	else if (stack_a->beginning->index == 1 - 1 \
	&& stack_a->beginning->next->index == 4 - 1 \
	&& stack_a->beginning->next->next->index == 3 - 1)
	{
		sa(stack_a->beginning);
		ra(stack_a);
		ra(stack_a);
		sa(stack_a->beginning);
		rra(stack_a);
	}
	four_num_one2(stack_a);
}

void	four_num_two2(t_stack *stack_a)
{
	if (stack_a->beginning->index == 2 - 1 \
	&& stack_a->beginning->next->index == 3 - 1)
	{
		ra(stack_a);
		sa(stack_a->beginning);
		rra(stack_a);
		sa(stack_a->beginning);
	}
	else if (stack_a->beginning->index == 2 - 1 \
	&& stack_a->beginning->next->index == 1 - 1 \
	&& stack_a->beginning->next->next->index == 4 - 1)
	{
		sa(stack_a->beginning);
		rra(stack_a);
		rra(stack_a);
		sa(stack_a->beginning);
		rra(stack_a);
		rra(stack_a);
	}
	else if (stack_a->beginning->index == 2 - 1 \
	&& stack_a->beginning->next->index == 1 - 1)
		sa(stack_a->beginning);
}

void	four_num_two(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->beginning->index == 2 - 1 \
	&& stack_a->beginning->next->index == 4 - 1 \
	&& stack_a->beginning->next->next->index == 3 - 1)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		sa(stack_a->beginning);
		pa(stack_b, stack_a);
		pa(stack_b, stack_a);
	}
	else if (stack_a->beginning->index == 2 - 1 \
	&& stack_a->beginning->next->index == 4 - 1 \
	&& stack_a->beginning->next->next->index == 1 - 1)
	{
		rra(stack_a);
		sa(stack_a->beginning);
		rra(stack_a);
	}
	else if (stack_a->beginning->index == 2 - 1 \
	&& stack_a->beginning->next->index == 3 - 1 \
	&& stack_a->beginning->next->next->index == 4 - 1)
		rra(stack_a);
	four_num_two2(stack_a);
}
