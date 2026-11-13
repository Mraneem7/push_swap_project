#include "push_swap.h"

static int	parse_one(char *s, int *result)
{
	long long	n;
	long long	limit;
	int			sign;

	n = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		return (0);
	limit = 2147483647LL;
	if (sign == -1)
		limit = 2147483648LL;
	while (*s >= '0' && *s <= '9')
	{
		if (n > (limit - (*s - '0')) / 10)
			return (0);
		n = n * 10 + (*s++ - '0');
	}
	if (*s)
		return (0);
	*result = (int)(n * sign);
	return (1);
}

static int	has_duplicate(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->values[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	parse_numbers(t_stack *a, int argc, char **argv, int start)
{
	int	value;

	a->size = 0;
	a->values = malloc(sizeof(int) * (argc - start));
	if (!a->values)
		return (0);
	while (start < argc)
	{
		if (!parse_one(argv[start], &value))
			return (0);
		if (has_duplicate(a, value))
			return (0);
		a->values[a->size] = value;
		a->size++;
		start++;
	}
	return (1);
}
