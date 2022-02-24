/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_num_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 02:07:43 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 13:36:52 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	four_num_four3(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->beginning->index == 4 - 1 \
	&& stack_a->beginning->next->index == 1 - 1 \
	&& stack_a->beginning->next->next->index == 3 - 1)
	{
		sa(stack_a->beginning);
		pb(stack_a, stack_b);
		ra(stack_a);
		sa(stack_a->beginning);
		pa(stack_b, stack_a);
	}
}

void	four_num_four2(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->beginning->index == 4 - 1 \
	&& stack_a->beginning->next->index == 2 - 1 \
	&& stack_a->beginning->next->next->index == 3 - 1)
	{
		rra(stack_a);
		sa(stack_a->beginning);
		ra(stack_a);
	}
	else if (stack_a->beginning->index == 4 - 1 \
	&& stack_a->beginning->next->index == 2 - 1 \
	&& stack_a->beginning->next->next->index == 1 - 1)
	{
		ra(stack_a);
		sa(stack_a->beginning);
	}
	four_num_four3(stack_a, stack_b);
}

void	four_num_four(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->beginning->index == 4 - 1 \
	&& stack_a->beginning->next->index == 3 - 1 \
	&& stack_a->beginning->next->next->index == 2 - 1)
	{
		sa(stack_a->beginning);
		rra(stack_a);
		rra(stack_a);
		sa(stack_a->beginning);
	}
	else if (stack_a->beginning->index == 4 - 1 \
	&& stack_a->beginning->next->index == 3 - 1 \
	&& stack_a->beginning->next->next->index == 1 - 1)
	{
		sa(stack_a->beginning);
		ra(stack_a);
		ra(stack_a);
	}
	four_num_four2(stack_a, stack_b);
	if (stack_a->beginning->index == 4 - 1 \
	&& stack_a->beginning->next->index == 1 - 1 \
	&& stack_a->beginning->next->next->index == 2 - 1)
	{
		ra(stack_a);
	}
}
