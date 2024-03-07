/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:29:31 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/06 13:28:42 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					pos;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	struct s_stack_node	*next;
}	t_stack_node;

//split
char			**ft_split(char const *s, char c, char const *s0);
size_t			ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);

//stack creation
void			stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
void			init_nodes(t_stack_node *a, t_stack_node *b);
long			ft_atoi(const char *str);

//stack set
int				find_max_index(t_stack_node *str);
t_stack_node	*find_low_index(t_stack_node *str);
t_stack_node	*find_cheapest(t_stack_node **b);
void			set_index(t_stack_node *stack);
void			set_current_position(t_stack_node **stack);
void			set_target_position(t_stack_node **b, t_stack_node **a);
void			set_cost_b(t_stack_node **stack);
void			set_cost_a(t_stack_node **b, t_stack_node **a);

//stack order
void			push_swap(t_stack_node **a, t_stack_node **b);
void			push(t_stack_node **src, t_stack_node **dst);
void			swap(t_stack_node **lst);
void			rotate(t_stack_node **lst);
void			reverse_rotate(t_stack_node **lst);
void			sa(t_stack_node **a, bool check);
void			sb(t_stack_node **b, bool check);
void			ss(t_stack_node **a, t_stack_node **b, bool check);
void			pa(t_stack_node **b, t_stack_node **a, bool check);
void			pb(t_stack_node **b, t_stack_node **a, bool check);
void			ra(t_stack_node **a, bool check);
void			rb(t_stack_node **b, bool check);
void			rr(t_stack_node **a, t_stack_node **b, bool check);
void			rra(t_stack_node **a, bool check);
void			rrb(t_stack_node **b, bool check);
void			rrr(t_stack_node **a, t_stack_node **b, bool check);

//stack order sorter
bool			stack_sorted(t_stack_node *a);
bool			stack_sorted_2(t_stack_node *a);
void			stack_3(t_stack_node **stack);
void			stack_4(t_stack_node **a, t_stack_node **b);

//stack utils
int				stack_len(t_stack_node *stack);
int				ft_abs(int nbr);

//error-free
int				error_free(t_stack_node **a, char **argv, bool flag_argc_2);
void			free_matrix(char **argv);
void			free_stack(t_stack_node **stack);
int				error_syntax(char *str);
int				error_repetition(t_stack_node *a, int nbr);

//steps
void			step_1(t_stack_node **a, t_stack_node **b);
void			step_2(t_stack_node **a, t_stack_node **b);
void			step_2_order(t_stack_node **a, t_stack_node **b, int i, int j);
void			step_3(t_stack_node **a);
void			set_low_head(t_stack_node **a, int size_stack);
t_stack_node	*find_nodo_low_index(t_stack_node *str);
void			set_max_tail(t_stack_node **a, int size_stack);
t_stack_node	*find_nodo_max_index(t_stack_node *str);

//get_next_line
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			*static_maker(char *static_str, int fd);
char			*make_line(char *static_str, int i);
char			*new_static_maker(char *static_str);
char			*get_next_line(int fd);

//borrar
void			print_stack(t_stack_node *stack);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

#endif