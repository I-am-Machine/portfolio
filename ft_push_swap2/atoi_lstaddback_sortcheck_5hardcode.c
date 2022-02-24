/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_lstaddback_sortcheck_5hardcode.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:03:35 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 01:13:05 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi2(const char *str)
{
	long	i;
	long	value;
	long	neg;

	i = 0;
	value = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || neg == -1)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - 48);
		i++;
	}
	return (value * neg);
}

void	doubly_lstaddback(t_list *head, t_list *node)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
	node->previous = tmp;
}

int	five_hardcode2(t_stack *stack_a, t_stack *stack_b, int check)
{
	if (stack_a->beginning->index == 5 - 1 \
	&& stack_a->beginning->next->index == 2 - 1 \
	&& stack_a->beginning->next->next->index == 4 - 1 \
	&& stack_a->beginning->next->next->next->index == 3 - 1)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		sa(stack_a->beginning);
		pb(stack_a, stack_b);
		ra(stack_a);
		sa(stack_a->beginning);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		check = 1;
	}
	return (check);
}

int	five_hardcode(t_stack *stack_a, t_stack *stack_b)
{
	int	check;

	check = 0;
	if (stack_a->beginning->index == 5 - 1 \
	&& stack_a->beginning->next->index == 4 - 1 \
	&& stack_a->beginning->next->next->index == 1 - 1 \
	&& stack_a->beginning->next->next->next->index == 2 - 1)
	{
		sa(stack_a->beginning);
		ra(stack_a);
		ra(stack_a);
		check = 1;
	}
	check = five_hardcode2(stack_a, stack_b, check);
	return (check);
}

int	sort_check(t_stack *stack_a)
{
	t_list	*tmp;
	int		lowest;
	int		check;

	tmp = stack_a->beginning;
	lowest = tmp->value;
	check = lowest;
	while (tmp->next != NULL)
	{
		if (tmp->index)
		{
		}
		tmp = tmp->next;
	}
	if (check == lowest)
		return (0);
	return (1);
}
