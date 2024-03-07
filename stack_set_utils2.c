/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:08:00 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/20 15:47:16 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

t_stack_node	*find_nodo_max_index(t_stack_node *str)
{
	t_stack_node	*max_index;

	max_index = str;
	while (str)
	{
		if (str->index > max_index->index)
			max_index = str;
		str = str->next;
	}
	return (max_index);
}

t_stack_node	*find_nodo_low_index(t_stack_node *str)
{
	t_stack_node	*low_index;

	low_index = str;
	while (str)
	{
		if (str->index < low_index->index)
			low_index = str;
		str = str->next;
	}
	return (low_index);
}

void	step_2_order(t_stack_node **a, t_stack_node **b, int i, int j)
{
	while (j < 0)
	{
		rrb (b, false);
		j++;
	}
	while (j > 0)
	{
		rb (b, false);
		j--;
	}
	while (i < 0)
	{
		rra (a, false);
		i++;
	}
	while (i > 0)
	{
		ra (a, false);
		i--;
	}
}
