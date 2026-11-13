#include "push_swap.h"

static int	print_error(t_stack *a)
{
	free(a->values);
	write(2, "Error\n", 6);
	return (1);
}

static int	is_simple(char *s)
{
	char	*flag;

	flag = "--simple";
	while (*s && *flag && *s == *flag)
	{
		s++;
		flag++;
	}
	return (*s == '\0' && *flag == '\0');
}

int	main(int argc, char **argv)
{
	t_stack	a;
	int		start;

	if (argc == 1)
		return (0);
	a.values = NULL;
	a.size = 0;
	start = 1;
	if (is_simple(argv[1]))
		start = 2;
	if (start == argc)
		return (print_error(&a));
	if (!parse_numbers(&a, argc, argv, start))
		return (print_error(&a));
	bubble_sort(&a);
	free(a.values);
	return (0);
}
