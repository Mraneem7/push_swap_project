#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*values;
	int	size;
} t_stack;

int		parse_numbers(t_stack *a, int argc, char **argv, int start);
void	sa(t_stack *a);
void	ra(t_stack *a);
int		stack_is_sorted(t_stack *a);
void	bubble_sort(t_stack *a);

#endif
