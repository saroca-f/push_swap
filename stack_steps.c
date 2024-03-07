/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:38:08 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/20 15:00:42 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	step_1(t_stack_node **a, t_stack_node **b)
{
	int				mid;
	int				i;
	int				size;

	mid = stack_len(*a) / 2;
	i = 0;
	size = stack_len(*a);
	if (stack_len(*a) == 4)
	{
		while ((*a)->index != find_nodo_low_index(*a)->index)
			ra (a, false);
		return (pb(b, a, false));
	}
	while (i < size && (stack_len(*a) != 3) && !stack_sorted(*a))
	{
		if ((*a)->index <= mid)
			pb(b, a, false);
		else
			ra (a, false);
		i++;
	}
	while (!(stack_len(*a) <= 3) && !stack_sorted(*a))
		pb(b, a, false);
}

void	step_2(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap;
	int				i;
	int				j;

	cheap = find_cheapest(b);
	i = cheap->cost_a;
	j = cheap->cost_b;
	while (j < 0 && i < 0)
	{
		rrr (a, b, false);
		j++;
		i++;
	}
	while (i > 0 && j > 0)
	{
		rr (a, b, false);
		j--;
		i--;
	}
	step_2_order(a, b, i, j);
	pa (b, a, false);
}

void	step_3(t_stack_node **a)
{
	int				size_stack;

	if (stack_len(*a) % 2 != 0)
		size_stack = stack_len(*a) + 1;
	else
		size_stack = stack_len(*a);
	set_max_tail(a, size_stack);
}
