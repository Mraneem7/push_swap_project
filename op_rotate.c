/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   op_ft_rotate.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mrayamma <mrayamma@student.42abudhabi.ae> #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 10:20:15 by mrayamma         #+#    #+#              */
/*   Updated: 2026/11/21 10:20:15 by mrayamma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = stack->top->next;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack *a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
