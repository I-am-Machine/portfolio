/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bexner <bexner@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:32:02 by bexner            #+#    #+#             */
/*   Updated: 2022/02/22 23:03:09 by bexner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				check;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef struct t_listp
{
	t_list	*beginning;
	t_list	*end;
	int		value;
}	t_stack;

long	ft_atoi2(const char *str);
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	sa(t_list *a_stack);
void	sb(t_list *a_stack);
void	ss(t_list *a_stack, t_list *b_stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	doubly_lstaddback(t_list *head, t_list *node);
void	ft_radix(t_stack *stack_a, t_stack *stack_b, int size);
t_list	*ft_lstnew2(int valueinput);
int		number_of_elements(t_list *a_stack);
void	hardcode_sort(t_stack *stack_a, t_stack *stack_b, int argc);
int		find_lowest_index(t_stack *stack_a);
void	doubly_lst_print(t_list *head);
void	index_sort(t_stack *stack_a);
int		five_hardcode(t_stack *stack_a, t_stack *stack_b);
void	activate_four_num_sort(t_stack *stack_a, int check, int lowest_index);
void	create_a_stack(t_list *a_stack, t_stack *stack_a, char **argv);
int		bitlength(int num);
void	four_num_three(t_stack *stack_a);
void	four_num_four(t_stack *stack_a, t_stack *stack_b);
void	four_num_one(t_stack *stack_a);
void	four_num_two(t_stack *stack_a, t_stack *stack_b);
void	free_all(t_stack *stack_a, t_stack *stack_b);

#endif