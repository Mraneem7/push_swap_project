/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrayamma <mrayamma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 12:23:28 by mrayamma          #+#    #+#             */
/*   Updated: 2026/11/21 12:29:48 by mrayamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	t_node	*cur;

	if (!a || a->size < 2)
		return (1);
	cur = a->top;
	while (cur->next)
	{
		if (cur->index > cur->next->index)
			return (0);
		cur = cur->next;
	}
	return (1);
}

double	ft_compute_disorder(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	long	inv;
	long	max_inv;

	if (!a || a->size < 2)
		return (0.0);
	inv = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->index > j->index)
				inv++;
			j = j->next;
		}
		i = i->next;
	}
	max_inv = (long) a->size * (a->size - 1) / 2;
	return ((double) inv / (double) max_inv);
}

static void	ft_adaptive_sort(t_stack *a, t_stack *b)
{
	double	disorder;

	if (a->size <= 5)
	{
		ft_sort_simple(a, b);
		return ;
	}
	disorder = ft_compute_disorder(a);
	if (disorder < 0.2)
		ft_sort_simple(a, b);
	else if (disorder < 0.5)
		ft_sort_medium(a, b);
	else
		ft_sort_complex(a, b);
}

void	ft_sort_controller(t_stack *a, t_stack *b, t_strategy mode)
{
	if (ft_is_sorted(a))
		return ;
	if (mode == STRAT_SIMPLE)
		ft_sort_simple(a, b);
	else if (mode == STRAT_MEDIUM)
		ft_sort_medium(a, b);
	else if (mode == STRAT_COMPLEX)
		ft_sort_complex(a, b);
	else
		ft_adaptive_sort(a, b);
}
