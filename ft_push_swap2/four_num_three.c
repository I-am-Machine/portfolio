/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_num_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:49:33 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 13:35:49 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	four_num_three3(t_stack *stack_a)
{
	if (stack_a->beginning->index == 3 - 1 \
	&& stack_a->beginning->next->index == 1 - 1)
	{
		sa(stack_a->beginning);
		ra(stack_a);
		sa(stack_a->beginning);
		rra(stack_a);
	}
	else if (stack_a->beginning->index == 3 - 1 \
	&& stack_a->beginning->next->index == 4 - 1 \
	&& stack_a->beginning->next->next->index == 1 - 1)
	{
		ra(stack_a);
		ra(stack_a);
	}
}

void	four_num_three2(t_stack *stack_a)
{
	if (stack_a->beginning->index == 3 - 1 \
	&& stack_a->beginning->next->index == 2 - 1 \
	&& stack_a->beginning->next->next->index == 4 - 1)
	{
		sa(stack_a->beginning);
		rra(stack_a);
	}
	else if (stack_a->beginning->index == 3 - 1 \
	&& stack_a->beginning->next->index == 1 - 1 \
	&& stack_a->beginning->next->next->index == 4 - 1 \
	&& stack_a->beginning->next->next->next->index == 2 - 1)
	{
		sa(stack_a->beginning);
		rra(stack_a);
		sa(stack_a->beginning);
	}
	four_num_three3(stack_a);
}

void	four_num_three(t_stack *stack_a)
{
	if (stack_a->beginning->index == 3 - 1 \
	&& stack_a->beginning->next->index == 4 - 1 \
	&& stack_a->beginning->next->next->index == 2 - 1)
	{
		rra(stack_a);
		rra(stack_a);
		sa(stack_a->beginning);
	}
	else if (stack_a->beginning->index == 3 - 1 \
	&& stack_a->beginning->next->index == 2 - 1 \
	&& stack_a->beginning->next->next->index == 1 - 1)
	{
		sa(stack_a->beginning);
		ra(stack_a);
		sa(stack_a->beginning);
		rra(stack_a);
		sa(stack_a->beginning);
	}
	four_num_three2(stack_a);
}
