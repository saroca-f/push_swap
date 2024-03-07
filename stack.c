/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:32:07 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/06 13:23:47 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		cont;
	int		sig;
	long	imp;

	cont = 0;
	sig = 1;
	imp = 0;
	while ((str[cont] == ' ') || (str[cont] == '\t') || (str[cont] == '\r')
		|| (str[cont] == '\n') || (str[cont] == '\f') || (str[cont] == '\v'))
		cont++;
	if ((str[cont] == '-') || (str[cont] == '+'))
	{
		if (str[cont] == '-')
			sig = -1;
		cont++;
	}
	while ((str[cont] >= '0') && (str[cont] <= '9'))
		imp = ((imp * 10) + (str[cont++] - '0'));
	return (imp * sig);
}

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	node->index = 0;
	if (!*stack)
		*stack = node;
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
	}
}

void	stack_init(t_stack_node **a, char **argv, bool argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]) == 1)
			error_free(a, argv, argc_2);
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, argc_2);
		if (error_repetition(*a, (int)nbr) == 1)
			error_free(a, argv, argc_2);
		append_node (a, (int)nbr);
		++i;
	}
	if (argc_2)
		free_matrix(argv);
}

void	print_stack(t_stack_node *stack)
{
	t_stack_node	*current;
	int				len;

	current = stack;
	len = 0;
	while (current != NULL)
	{
		printf("Valor: %d ", current->value);
		printf("Índice: %d ", current->index);
		printf("Posición: %d ", current->pos);
		printf("Target: %d ", current->target_pos);
		printf("Coste A: %d ", current->cost_a);
		printf("Coste B: %d\n", current->cost_b);
		len++;
		current = current->next;
	}
	printf("Tamaño del stack: %d\n", len);
}
