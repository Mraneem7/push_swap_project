/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrayamma <mrayamma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 12:30:39 by mrayamma          #+#    #+#             */
/*   Updated: 2026/11/21 12:30:39 by mrayamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_parse_flag(int *argc, char ***argv, t_strategy *mode)
{
	*mode = STRAT_ADAPTIVE;
	if (*argc < 2 || (*argv)[1][0] != '-' || (*argv)[1][1] != '-')
		return (0);
	if (ft_strncmp((*argv)[1], "--simple", 9) == 0)
		*mode = STRAT_SIMPLE;
	else if (ft_strncmp((*argv)[1], "--medium", 9) == 0)
		*mode = STRAT_MEDIUM;
	else if (ft_strncmp((*argv)[1], "--complex", 10) == 0)
		*mode = STRAT_COMPLEX;
	else if (ft_strncmp((*argv)[1], "--adaptive", 11) == 0)
		*mode = STRAT_ADAPTIVE;
	else
		return (-1);
	(*argv)++;
	(*argc)--;
	return (1);
}

static void	ft_init_and_run(int *arr, int n, t_strategy mode)
{
	t_stack	a;
	t_stack	b;

	b.top = NULL;
	b.size = 0;
	if (!ft_init_stack_a(&a, arr, n))
	{
		free(arr);
		return ;
	}
	free(arr);
	ft_assign_index(&a);
	ft_sort_controller(&a, &b, mode);
	ft_free_stack(&a);
	ft_free_stack(&b);
}

int	main(int argc, char **argv)
{
	t_strategy	mode;
	int			*arr;
	int			n;

	if (argc < 2)
		return (0);
	if (ft_parse_flag(&argc, &argv, &mode) == -1)
		return (write(2, "Error\n", 6), 1);
	if (argc < 2)
		return (0);
	arr = ft_parse_args(argc, argv, &n);
	if (!arr)
		return (write(2, "Error\n", 6), 1);
	ft_init_and_run(arr, n, mode);
	return (0);
}
