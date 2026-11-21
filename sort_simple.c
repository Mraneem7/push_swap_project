/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrayamma <mrayamma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 12:27:48 by mrayamma          #+#    #+#             */
/*   Updated: 2026/11/21 12:27:48 by mrayamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min_pos(t_stack *a)
{
	t_node	*cur;
	int		min_idx;
	int		min_pos;
	int		pos;

	cur = a->top;
	min_idx = cur->index;
	min_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index < min_idx)
		{
			min_idx = cur->index;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (min_pos);
}

static void	ft_push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = ft_find_min_pos(a);
	if (min_pos <= a->size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		while (min_pos++ < a->size)
			rra(a);
	}
	pb(a, b);
}

void	ft_sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (!a || a->size < 3 || ft_is_sorted(a))
		return ;
	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && first > third)
		ra(a);
	else if (second > first && second > third)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
}

void	ft_sort_simple(t_stack *a, t_stack *b)
{
	if (!a || a->size < 2 || ft_is_sorted(a))
		return ;
	if (a->size == 2)
	{
		sa(a);
		return ;
	}
	while (a->size > 3 && !ft_is_sorted(a))
		ft_push_min_to_b(a, b);
	ft_sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
