/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:10:59 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 22:17:18 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	t_list	*first;
	t_list	*last;
	t_list	*last_second;

	write(1, "rra\n", 4);
	first = stack_a->beginning;
	if (stack_a->end != NULL)
		last = stack_a->end;
	else
	{
		last = stack_a->beginning;
		while (last->next != NULL)
			last = last->next;
	}
	last_second = last->previous;
	last->next = first;
	first->previous = last;
	last->previous = NULL;
	stack_a->beginning = last;
	stack_a->end = last_second;
	last_second->next = NULL;
}

void	rrb(t_stack *stack_b)
{
	t_list	*first;
	t_list	*last;
	t_list	*last_second;

	write(1, "rrb\n", 4);
	first = stack_b->beginning;
	last = stack_b->end;
	last_second = last->previous;
	last->next = first;
	first->previous = last;
	last->previous = NULL;
	stack_b->beginning = last;
	stack_b->end = last_second;
	last_second->next = NULL;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "rrr\n", 4);
	rra(stack_a);
	rrb(stack_b);
}
