/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrayamma <mrayamma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 12:28:02 by mrayamma          #+#    #+#             */
/*   Updated: 2026/11/21 12:28:02 by mrayamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	if (n <= 1)
		return (1);
	i = 1;
	while (i * i <= n && i <= 46340)
		i++;
	return (i - 1);
}

static int	ft_find_max_pos(t_stack *b)
{
	t_node	*cur;
	int		max_idx;
	int		max_pos;
	int		pos;

	cur = b->top;
	max_idx = cur->index;
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index > max_idx)
		{
			max_idx = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

static void	ft_push_chunks(t_stack *a, t_stack *b, int chunk)
{
	int	pushed;

	pushed = 0;
	while (a->size > 0)
	{
		if (a->top->index <= pushed)
		{
			pb(a, b);
			rb(b);
			pushed++;
		}
		else if (a->top->index <= pushed + chunk)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
}

void	ft_sort_medium(t_stack *a, t_stack *b)
{
	int	max_pos;

	if (!a || a->size < 2 || ft_is_sorted(a))
		return ;
	ft_push_chunks(a, b, ft_sqrt(a->size));
	while (b->size > 0)
	{
		max_pos = ft_find_max_pos(b);
		if (max_pos <= b->size / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			while (max_pos++ < b->size)
				rrb(b);
		}
		pa(a, b);
	}
}
