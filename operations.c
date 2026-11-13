#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (!a || a->size < 2)
		return ;
	temp = a->values[0];
	a->values[0] = a->values[1];
	a->values[1] = temp;
	write(1, "sa\n", 3);
}

void	ra(t_stack *a)
{
	int	first;
	int	i;

	if (!a || a->size < 2)
		return ;
	first = a->values[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->values[i] = a->values[i + 1];
		i++;
	}
	a->values[i] = first;
	write(1, "ra\n", 3);
}
