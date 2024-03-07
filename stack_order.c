/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:47:44 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/20 15:45:17 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a, bool check)
{
	swap(a);
	if (!check)
		write (1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool check)
{
	swap (b);
	if (!check)
		write (1, "sb\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool check)
{
	push (a, b);
	if (!check)
		write (1, "pb\n", 3);
}

void	pa(t_stack_node **b, t_stack_node **a, bool check)
{
	push (b, a);
	if (!check)
		write (1, "pa\n", 3);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	while (!stack_sorted(*a))
	{
		step_1(a, b);
		stack_3(a);
		while (*b)
		{
			if (stack_sorted(*b) && stack_len(*b) == 2)
				sb(b, false);
			set_target_position(b, a);
			set_cost_b(b);
			set_cost_a(b, a);
			if (stack_len(*b) == 1 && stack_sorted_2(*a))
				stack_4(a, b);
			else
				step_2 (a, b);
		}
		if (!stack_sorted(*a))
			step_3(a);
	}
}
