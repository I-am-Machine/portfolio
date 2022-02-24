/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_sa_sb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:08:02 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 22:18:25 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px_check(t_stack *stack_b, t_list *first_a, t_list *first_b)
{
	if (stack_b->beginning != NULL)
	{
		first_a->next = first_b;
		first_b->previous = first_a;
	}
	if (first_b == stack_b->beginning)
		first_b->previous = first_a;
	if (stack_b->beginning == NULL)
	{
		stack_b->beginning = first_a;
		stack_b->beginning->next = NULL;
		stack_b->beginning->previous = NULL;
	}
	if (stack_b->end == NULL)
	{
		while (first_a->next != NULL)
		{
			first_a = first_a->next;
		}
		stack_b->end = first_a;
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{	
	t_list	*first_a;
	t_list	*second_a;
	t_list	*first_b;

	write(1, "pb\n", 3);
	first_a = stack_a->beginning;
	if (stack_b->beginning != NULL)
	{
		first_b = stack_b->beginning;
		stack_b->beginning = first_a;
	}
	if (first_a->next != NULL)
	{
		second_a = first_a->next;
		second_a->previous = NULL;
		stack_a->beginning = second_a;
	}
	if (first_a->next == NULL)
	{
		stack_a->beginning = NULL;
		stack_a->end = NULL;
	}
	first_a->previous = NULL;
	px_check(stack_b, first_a, first_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{	
	t_list	*first_a;
	t_list	*second_a;
	t_list	*first_b;

	write(1, "pa\n", 3);
	first_a = stack_a->beginning;
	if (stack_b->beginning != NULL)
	{
		first_b = stack_b->beginning;
		stack_b->beginning = first_a;
	}
	if (first_a->next != NULL)
	{
		second_a = first_a->next;
		second_a->previous = NULL;
		stack_a->beginning = second_a;
	}
	if (first_a->next == NULL)
	{
		stack_a->beginning = NULL;
		stack_a->end = NULL;
	}
	first_a->previous = NULL;
	px_check(stack_b, first_a, first_b);
}

void	sa(t_list *a_stack)
{
	t_list	*first;
	t_list	*second;
	int		tmp;

	write(1, "sa\n", 3);
	first = a_stack;
	second = a_stack;
	second = second->next;
	tmp = second->value;
	second->value = first->value;
	first->value = tmp;
}

void	sb(t_list *a_stack)
{
	t_list	*first;
	t_list	*second;
	int		tmp;

	write(1, "sb\n", 3);
	first = a_stack;
	second = a_stack;
	second = second->next;
	tmp = second->value;
	second->value = first->value;
	first->value = tmp;
}
