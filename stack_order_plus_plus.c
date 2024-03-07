/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order_plus_plus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:53:59 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/19 19:39:52 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **a, bool check)
{
	rotate (a);
	if (!check)
		write (1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool check)
{
	rotate (b);
	if (!check)
		write (1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool check)
{
	rotate (a);
	rotate (b);
	if (!check)
		write (1, "rr\n", 3);
}
