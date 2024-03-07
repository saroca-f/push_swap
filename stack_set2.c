/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:48:34 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/19 10:12:07 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost_b(t_stack_node **stack)
{
	t_stack_node	*ret;
	int				size_stack;

	ret = *stack;
	size_stack = stack_len(*stack);
	while (ret)
	{
		if (size_stack % 2 == 0)
		{
			if (ret->pos <= (size_stack / 2))
				ret->cost_b = ret->pos - 1;
			if (ret->pos > (size_stack / 2))
				ret->cost_b = -(size_stack - (ret->pos) + 1);
		}
		if (size_stack % 2 != 0)
		{
			if (ret->pos <= ((size_stack / 2) + 1))
				ret->cost_b = ret->pos - 1;
			if (ret->pos > ((size_stack / 2) + 1))
				ret->cost_b = -(size_stack - (ret->pos) + 1);
		}
		ret = ret->next;
	}
}

void	set_cost_a(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*temp;
	t_stack_node	*temp2;

	temp = *b;
	temp2 = *a;
	while (temp)
	{
		set_current_position(a);
		set_cost_b(a);
		while (temp->target_pos != (*a)->pos)
			(*a) = (*a)->next;
		temp->cost_a = (*a)->cost_b;
		(*a) = temp2;
		temp = temp->next;
	}
}
