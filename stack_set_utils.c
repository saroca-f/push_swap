/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:11:33 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/20 15:49:19 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_low_head(t_stack_node **a, int size_stack)
{
	t_stack_node	*low;

	low = find_nodo_low_index(*a);
	while (low->pos != 1)
	{
		if (low->pos == size_stack)
		{
			rra(a, false);
			return ;
		}
		if (low->pos <= (size_stack / 2))
		{
			ra(a, false);
			low->pos = low->pos - 1;
		}
		if (low->pos > (size_stack / 2))
		{
			rra(a, false);
			low->pos = low->pos + 1;
		}
	}
}

void	set_max_tail(t_stack_node **a, int size_stack)
{
	t_stack_node	*max;

	max = find_nodo_max_index(*a);
	while (max->pos != max->index)
	{
		if (max->pos <= (size_stack / 2))
			ra(a, false);
		if (max->pos > (size_stack / 2))
			rra(a, false);
		set_current_position(a);
	}
}

int	find_max_index(t_stack_node *str)
{
	int	max_index;

	max_index = 0;
	while (str)
	{
		if (str->index > max_index)
			max_index = str->index;
		str = str->next;
	}
	return (max_index);
}

t_stack_node	*find_low_index(t_stack_node *str)
{
	t_stack_node	*node;
	int				low_index;

	low_index = str->index;
	while (str)
	{
		if (str->index < low_index)
		{
			low_index = str->index;
			node = str;
		}
		str = str->next;
	}
	return (node);
}

t_stack_node	*find_cheapest(t_stack_node **b)
{
	t_stack_node	*ret;
	t_stack_node	*cheap;

	ret = *b;
	cheap = ret;
	while (ret)
	{
		if ((ft_abs(ret->cost_a) + ft_abs(ret->cost_b))
			< (ft_abs(cheap->cost_a) + ft_abs(cheap->cost_b)))
			cheap = ret;
		ret = ret->next;
	}
	return (cheap);
}
