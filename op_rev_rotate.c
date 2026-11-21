/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   op_ft_rev_rotate.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mrayamma <mrayamma@student.42abudhabi.ae> #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 10:20:41 by mrayamma         #+#    #+#              */
/*   Updated: 2026/11/21 10:20:41 by mrayamma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a)
{
	ft_rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	ft_rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	write(1, "rrr\n", 4);
}
