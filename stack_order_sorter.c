/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order_sorter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:10:11 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/20 15:30:28 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_3(t_stack_node **stack)
{
	t_stack_node	*p1;

	p1 = *stack;
	if (p1->value > p1->next->next->value && p1->value > p1->next->value)
		ra(stack, false);
	p1 = *stack;
	if (p1->next->value > p1->next->next->value && p1->next->value > p1->value)
		rra(stack, false);
	p1 = *stack;
	if (p1->value > p1->next->value)
		sa(stack, false);
}

void	stack_4(t_stack_node **a, t_stack_node **b)
{
	int				i;
	int				j;

	i = (*b)->cost_a;
	j = ((*b)->cost_b);
	step_2_order(a, b, i, j);
	pa(b, a, false);
	set_current_position(a);
	while (find_nodo_low_index(*a)->pos != 1)
	{
		if ((find_nodo_low_index(*a)->pos <= stack_len(*a) / 2)
			&& (stack_len(*a) % 2 == 0))
			ra(a, false);
		else if ((find_nodo_low_index(*a)->pos <= ((stack_len(*a) / 2) + 1))
			&& (stack_len(*a) % 2 != 0))
			ra(a, false);
		else
			rra(a, false);
		set_current_position(a);
	}
}

bool	stack_sorted(t_stack_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

bool	stack_sorted_2(t_stack_node *a)
{
	bool	check;

	check = false;
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->index != (a->next->index - 1) && check == true)
			return (false);
		if (a->index != (a->next->index - 1) && check == false)
			check = true;
		a = a->next;
	}
	return (true);
}
