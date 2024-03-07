/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:35:59 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/19 19:37:40 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack_node **a, t_stack_node **b, bool check)
{
	swap (a);
	swap (b);
	if (!check)
		write (1, "ss\n", 3);
}

void	rra(t_stack_node **a, bool check)
{
	reverse_rotate (a);
	if (!check)
		write (1, "rra\n", 4);
}

void	rrb(t_stack_node **a, bool check)
{
	reverse_rotate (a);
	if (!check)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool check)
{
	reverse_rotate (a);
	reverse_rotate (b);
	if (!check)
		write (1, "rrr\n", 4);
}
