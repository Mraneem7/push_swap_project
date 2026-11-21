/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrayamma <mrayamma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 10:27:38 by mrayamma          #+#    #+#             */
/*   Updated: 2026/11/21 12:32:34 by mrayamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

/* Parsing (parse_args.c & parse_utils.c) */
int		*ft_parse_args(int argc, char **argv, int *n);
void	ft_free_split(char **split);
int		ft_is_valid_number(const char *str);
long	ft_atol(const char *str);
int		ft_has_duplicate(int *arr, int size, int val);

/* Stack Initialization & Memory (stack_init.c) */
int		ft_init_stack_a(t_stack *a, int *arr, int n);
void	ft_assign_index(t_stack *a);
void	ft_free_stack(t_stack *stack);

/* Stack Operations (op_swap.c, op_push.c, op_rotate.c, op_rev_rotate.c) */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Sorting Controller & Algorithms (sort_*.c) */
int		ft_is_sorted(t_stack *a);
double	ft_compute_disorder(t_stack *a);
void	ft_sort_controller(t_stack *a, t_stack *b, t_strategy mode);
void	ft_sort_three(t_stack *a);
void	ft_sort_simple(t_stack *a, t_stack *b);
void	ft_sort_medium(t_stack *a, t_stack *b);
void	ft_sort_complex(t_stack *a, t_stack *b);

#endif
