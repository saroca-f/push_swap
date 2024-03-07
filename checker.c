/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:21:31 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/06 14:32:55 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2
		&& *str_1)
	{
		++str_1;
		++str_2;
	}
	if (*str_1 || *str_2)
		return (false);
	return (true);
}

void	find_error(t_stack_node *a, t_stack_node *b)
{
	free_stack(&a);
	free_stack(&b);
	write(2, "Error\n", 6);
	exit (1);
}

void	order_cheker(char *next_line, t_stack_node **a, t_stack_node **b)
{
	if (ft_strcmp(next_line, "pa\n"))
		pa(b, a, true);
	else if (ft_strcmp(next_line, "pb\n"))
		pb(b, a, true);
	else if (ft_strcmp(next_line, "sa\n"))
		sa(a, true);
	else if (ft_strcmp(next_line, "sb\n"))
		sb(b, true);
	else if (ft_strcmp(next_line, "ss\n"))
		ss(a, b, true);
	else if (ft_strcmp(next_line, "ra\n"))
		ra(a, true);
	else if (ft_strcmp(next_line, "rb\n"))
		rb(b, true);
	else if (ft_strcmp(next_line, "rr\n"))
		rr(a, b, true);
	else if (ft_strcmp(next_line, "rra\n"))
		rra(a, true);
	else if (ft_strcmp(next_line, "rrb\n"))
		rrb(b, true);
	else if (ft_strcmp(next_line, "rrr\n"))
		rrr(a, b, true);
	else
		find_error(*a, *b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*next_line;	
	int				len;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ', argv[0]);
	stack_init(&a, argv + 1, argc == 2);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		order_cheker(next_line, &a, &b);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(a) && stack_len(a) == len)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	return (0);
}
