/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benito_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:02:08 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 17:13:16 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lowest_numb(t_list *lowest_nbr)
{
	int		lowest_numb;

	lowest_numb = lowest_nbr->value;
	while (lowest_nbr->next != NULL)
	{
		if (lowest_nbr->value < lowest_numb)
			lowest_numb = lowest_nbr->value;
		lowest_nbr = lowest_nbr->next;
	}
	if (lowest_nbr->value < lowest_numb)
		lowest_numb = lowest_nbr->value;
	while (lowest_nbr->previous != NULL)
		lowest_nbr = lowest_nbr->previous;
	return (lowest_numb);
}

int	find_backwards_index(int lowest_numb, t_list *lowest_nbr, int lowest_index2)
{
	int		check;
	t_list	*tmp;

	tmp = lowest_nbr;
	check = 0;
	lowest_numb = find_lowest_numb(tmp);
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->previous != NULL)
	{
		if (check == 0)
			lowest_index2++;
		if (tmp->value == lowest_numb)
			check = 1;
		tmp = tmp->previous;
	}
	return (lowest_index2);
}

int	find_lowest_index(t_stack *stack_a)
{
	t_list	*lowest_nbr;
	int		lowest_numb;
	int		lowest_index;
	int		lowest_index2;
	int		check2;

	check2 = 0;
	lowest_index = 0;
	lowest_nbr = stack_a->beginning;
	lowest_numb = find_lowest_numb(lowest_nbr);
	lowest_index2 = find_backwards_index(lowest_numb, stack_a->beginning, 0);
	while (lowest_nbr->next != NULL)
	{
		if (check2 == 0)
			lowest_index++;
		if (lowest_nbr->value == lowest_numb)
			check2 = 1;
		lowest_nbr = lowest_nbr->next;
	}
	if (lowest_index2 < lowest_index)
	{
		return ((-1) * lowest_index2);
	}
	return (lowest_index);
}
