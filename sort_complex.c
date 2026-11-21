/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrayamma <mrayamma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:01:26 by mrayamma          #+#    #+#             */
/*   Updated: 2026/11/21 13:01:26 by mrayamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_max_bits(int size)
{
	int	max_num;
	int	max_bits;

	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	ft_radix_pass(t_stack *a, t_stack *b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((a->top->index >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	while (b->size > 0)
		pa(a, b);
}

void	ft_sort_complex(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_bits;
	int	size;

	if (!a || a->size < 2)
		return ;
	size = a->size;
	max_bits = ft_get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		ft_radix_pass(a, b, bit, size);
		bit++;
	}
}
