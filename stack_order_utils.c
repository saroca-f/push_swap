/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:49:55 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/06 13:06:30 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack->next)
	{
		count++;
		stack = stack->next;
	}
	count = count + 1;
	return (count);
}

void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*srcret;
	t_stack_node	*dstret;

	if (!*src)
		return ;
	srcret = *src;
	dstret = *dst;
	if (!*dst)
	{
		*src = srcret->next;
		srcret->next = NULL;
		*dst = srcret;
	}
	else
	{
		*src = srcret->next;
		srcret->next = *dst;
		*dst = srcret;
	}
}

void	swap(t_stack_node **lst)
{
	t_stack_node	*ret;
	t_stack_node	*ret2;

	if (stack_len(*lst) <= 1)
		return ;
	ret = *lst;
	ret2 = ret->next;
	ret->next = ret2->next;
	ret2->next = ret;
	*lst = ret2;
}

void	rotate(t_stack_node **lst)
{
	t_stack_node	*ret;
	t_stack_node	*fij;

	if (stack_len(*lst) <= 0)
		return ;
	ret = *lst;
	fij = *lst;
	while (ret->next)
		ret = ret->next;
	ret->next = fij;
	*lst = fij->next;
	fij->next = NULL;
	ret = *lst;
}

void	reverse_rotate(t_stack_node **lst)
{
	t_stack_node	*first;
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (stack_len(*lst) <= 0)
		return ;
	first = *lst;
	last = *lst;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = first;
	*lst = last;
}
