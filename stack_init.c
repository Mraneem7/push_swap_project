/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrayamma <mrayamma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 11:43:33 by mrayamma          #+#    #+#             */
/*   Updated: 2026/11/21 12:54:20 by mrayamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_new_node(int value)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

static void	ft_append_node(t_stack *a, t_node *node)
{
	t_node	*cur;

	if (!a->top)
		a->top = node;
	else
	{
		cur = a->top;
		while (cur->next)
			cur = cur->next;
		cur->next = node;
	}
	a->size++;
}

int	ft_init_stack_a(t_stack *a, int *arr, int n)
{
	t_node	*node;
	int		i;

	a->top = NULL;
	a->size = 0;
	i = 0;
	while (i < n)
	{
		node = ft_new_node(arr[i]);
		if (!node)
		{
			ft_free_stack(a);
			return (0);
		}
		ft_append_node(a, node);
		i++;
	}
	return (1);
}

void	ft_assign_index(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;
	int		rank;

	cur = a->top;
	while (cur)
	{
		rank = 0;
		cmp = a->top;
		while (cmp)
		{
			if (cur->value > cmp->value)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->size = 0;
}
