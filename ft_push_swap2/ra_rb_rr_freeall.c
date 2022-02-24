/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_freeall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:09:23 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 23:02:10 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	write(1, "ra\n", 3);
	first = stack_a->beginning;
	last = stack_a->beginning;
	while (last->next != NULL)
	{
		last = last->next;
	}
	second = first->next;
	last->next = first;
	first->next = NULL;
	first->previous = last;
	second->previous = NULL;
	stack_a->beginning = second;
	stack_a->end = first;
}

void	rb(t_stack *stack_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	write(1, "rb\n", 3);
	first = stack_b->beginning;
	last = stack_b->beginning;
	while (last->next != NULL)
	{
		last = last->next;
	}
	second = first->next;
	last->next = first;
	first->next = NULL;
	first->previous = last;
	second->previous = NULL;
	stack_b->beginning = second;
	stack_b->end = first;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "rr\n", 3);
	ra(stack_a);
	rb(stack_b);
}

void	free_all(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*a;
	t_list	*b;

	a = stack_a->beginning;
	b = stack_b->beginning;
	if (a)
	{
		while (a->next != NULL)
		{
			free(a);
			a = a->next;
		}
		free(a);
	}
	if (b)
	{
		while (b->next != NULL)
		{
			free(b);
			b = b->next;
		}
		free(b);
	}
	free(stack_b);
	free(stack_a);
}
