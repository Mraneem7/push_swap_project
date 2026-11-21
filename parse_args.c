/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrayamma <mrayamma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 11:54:13 by mrayamma          #+#    #+#             */
/*   Updated: 2026/11/21 11:54:13 by mrayamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_numbers(int argc, char **argv)
{
	char	**split;
	int		total;
	int		i;
	int		j;

	total = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			return (ft_free_split(split), -1);
		j = 0;
		while (split[j])
			j++;
		total += j;
		ft_free_split(split);
		i++;
	}
	return (total);
}

static int	ft_parse_tokens(char **split, int *arr, int *idx)
{
	long	val;
	int		j;

	j = 0;
	while (split[j])
	{
		if (!ft_is_valid_number(split[j]))
			return (0);
		val = ft_atol(split[j]);
		if (val > INT_MAX || val < INT_MIN)
			return (0);
		if (ft_has_duplicate(arr, *idx, (int) val))
			return (0);
		arr[*idx] = (int) val;
		(*idx)++;
		j++;
	}
	return (1);
}

static int	ft_fill_array(int argc, char **argv, int *arr)
{
	char	**split;
	int		i;
	int		idx;

	i = 1;
	idx = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		if (!ft_parse_tokens(split, arr, &idx))
			return (ft_free_split(split), 0);
		ft_free_split(split);
		i++;
	}
	return (1);
}

int	*ft_parse_args(int argc, char **argv, int *n)
{
	int	*arr;

	*n = ft_count_numbers(argc, argv);
	if (*n <= 0)
		return (NULL);
	arr = (int *) malloc(sizeof(int) * (*n));
	if (!arr)
		return (NULL);
	if (!ft_fill_array(argc, argv, arr))
		return (free(arr), NULL);
	return (arr);
}
