/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:59:31 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 01:19:40 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lowest(t_stack *stack_a)
{
	int		lowest;
	t_list	*tmp;

	tmp = stack_a->beginning;
	lowest = tmp->value;
	while (tmp->next != NULL)
	{
		if (tmp->value < lowest)
			lowest = tmp->value;
		tmp = tmp->next;
	}
	return (lowest);
}

void	index_now(t_stack *stack_a, int num_ele, int *array)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = stack_a->beginning;
	while (i < num_ele)
	{
		while (j < num_ele)
		{
			if (tmp->value == array[j])
				tmp->index = j;
			j++;
		}
		if (tmp->next != NULL)
			tmp = tmp->next;
		j = 0;
		i++;
	}
	free(array);
}

void	bubble_sort(t_stack *stack_a, int *array)
{
	int	i;
	int	j;
	int	num_ele;
	int	temp;

	i = 0;
	j = 0;
	num_ele = number_of_elements(stack_a->beginning);
	while (i < num_ele)
	{
		while (j < num_ele - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	index_now(stack_a, num_ele, array);
}

void	index_sort(t_stack *stack_a)
{
	t_list	*tmp;
	int		num_ele;
	int		i;
	int		*array;

	i = 0;
	num_ele = number_of_elements(stack_a->beginning);
	tmp = stack_a->beginning;
	array = malloc(num_ele * sizeof(int));
	while (tmp->next != NULL)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	array[i] = tmp->value;
	bubble_sort(stack_a, array);
}

void	ft_radix(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	max_bits;
	int	i;
	int	cur;
	int	j;

	max_bits = bitlength(size);
	i = 0;
	while (max_bits != 0)
	{
		j = 0;
		while (j < size)
		{
			cur = stack_a->beginning->index;
			if (((cur >> i) & 1))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		i++;
		while (stack_b->beginning != NULL)
			pa(stack_b, stack_a);
		max_bits--;
	}
}
