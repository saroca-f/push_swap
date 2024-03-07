/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:21:14 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/14 14:28:16 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **argv)
{
	int	i;

	i = 0;
	if (!argv || !*argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if (((str[i] == '-' || str[i] == '+')
			&& !(str[i + 1] >= '0' && str[i + 1] <= '9')))
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	error_repetition(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

int	error_free(t_stack_node **a, char **argv, bool argc_2)
{
	free_stack(a);
	if (argc_2)
		free_matrix(argv);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
