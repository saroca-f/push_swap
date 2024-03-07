/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:29:11 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/19 19:30:12 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ', argv[0]);
	stack_init(&a, argv + 1, argc == 2);
	set_index(a);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			if (a->value > a->next->value)
				sa(&a, false);
		if (stack_len(a) == 3)
			stack_3(&a);
		else
			push_swap(&a, &b);
	}
	if (argc == 2)
		free (argv);
	free_stack(&a);
	return (0);
}
