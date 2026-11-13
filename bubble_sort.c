#include "push_swap.h"

int	stack_is_sorted(t_stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->values[i] > a->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	bubble_pass(t_stack *a, int comparisons)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (i < comparisons && a->values[0] > a->values[1])
			sa(a);
		ra(a);
		i++;
	}
}

void	bubble_sort(t_stack *a)
{
	int	pass;

	if (!a || a->size < 2)
		return ;
	pass = 0;
	while (pass < a->size - 1 && !stack_is_sorted(a))
	{
		bubble_pass(a, a->size - pass - 1);
		pass++;
	}
}
