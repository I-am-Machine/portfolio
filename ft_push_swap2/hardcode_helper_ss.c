/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_helper_ss.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:00:39 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 22:54:00 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	activate_four_num_sort(t_stack *stack_a, int check, int lowest_index)
{
	int	i;

	i = 0;
	if (lowest_index > 0 && check == 0)
	{
		while (i < lowest_index - 1)
		{
			ra(stack_a);
			i++;
		}
	}
	else if (lowest_index < 0 && check == 0)
	{
		lowest_index = lowest_index * (-1);
		while (i < lowest_index)
		{
			rra(stack_a);
			i++;
		}
	}
}

void	create_a_stack(t_list *a_stack, t_stack *stack_a, char **argv)
{
	int		i;
	int		atoi;
	t_list	*tmp;

	i = 1;
	while (argv[i])
	{
		if (i == 1)
		{
			atoi = (int)ft_atoi2(argv[i]);
			a_stack = ft_lstnew2(atoi);
			i++;
		}
		atoi = (int)ft_atoi2(argv[i]);
		tmp = ft_lstnew2(atoi);
		doubly_lstaddback(a_stack, tmp);
		i++;
	}
	stack_a->beginning = a_stack;
	while (a_stack)
		a_stack = a_stack->next;
	stack_a->end = a_stack;
}

void	ss(t_list *a_stack, t_list *b_stack)
{
	write(1, "ss\n", 4);
	sa(a_stack);
	sb(b_stack);
}

int	bitlength(int num)
{
	int	bits;

	bits = 0;
	while ((num >> bits) != 0)
		bits++;
	return (bits);
}
