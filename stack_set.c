/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:44:04 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/16 20:02:04 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack_node *stack)
{
	int				i;
	t_stack_node	*temp;
	t_stack_node	*ret;

	i = 1;
	temp = stack;
	ret = temp;
	if (!stack)
		return ;
	while (i <= stack_len(stack))
	{
		while (temp)
		{
			if ((temp->value < ret->value && temp->index == 0)
				|| (ret->index != 0 && temp->index == 0))
				ret = temp;
			temp = temp->next;
		}
		ret->index = i++;
		temp = stack;
		ret = temp;
	}
}

void	set_current_position(t_stack_node **stack)
{
	int				i;
	t_stack_node	*ret;

	i = 1;
	ret = *stack;
	while (ret)
	{
		ret->pos = i;
		i++;
		ret = ret->next;
	}
}

bool	last_index(t_stack_node	*reta, t_stack_node *retb, int ret, int ret2)
{
	int	recort;

	recort = reta->index - retb->index;
	if (recort > ret2 && ret > 0)
	{
		retb->target_pos = reta->next->pos;
		return (true);
	}
	else if (recort > ret)
	{
		if (reta->next)
			retb->target_pos = reta->next->pos;
		else
			retb->target_pos = reta->pos;
		return (true);
	}
	return (false);
}

int	find_target(t_stack_node *a, int b_index, int target_index, int target_pos)
{
	t_stack_node	*reta;

	reta = a;
	while (reta)
	{
		if (reta->index > b_index && (reta->index < target_index))
		{
			target_index = reta->index;
			target_pos = reta->pos;
		}
		reta = reta->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	reta = a;
	while (reta)
	{
		if (reta->index < target_index)
		{
			target_index = reta->index;
			target_pos = reta->pos;
		}
		reta = reta->next;
	}
	return (target_pos);
}

void	set_target_position(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*retb;
	int				i;
	int				target_pos;

	retb = *b;
	i = 0;
	set_current_position(a);
	set_current_position(b);
	target_pos = 0;
	while (retb)
	{
		target_pos = find_target(*a, retb->index, INT_MAX, target_pos);
		retb->target_pos = target_pos;
		retb = retb->next;
	}
}
