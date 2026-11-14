/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_simple_sort.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mrayamma <mrayamma@student.42abudhabi.ae> #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/11 19:51:28 by mrayamma         #+#    #+#              */
/*   Updated: 2026/11/14 11:39:08 by mrayamma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*create_array(int argc, char **argv, int n)
{
	int	i;
	int	*arr;

	n = argc - 1;
	arr = malloc(sizeof(int)*n);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < n)
	{
		arr[i] = atoi(argv[i + 1]);
		i++;
	}
	return (arr);
}

int	*ft_insertion_sort(int *arr, int n)
{
	int	i;
	int	min_id;
	int	key;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		min_id = i - 1;
		while (min_id >= 0 && arr[min_id] > key)
		{
			arr[min_id + 1] = arr[min_id];
			min_id--;
		}
		arr[min_id + 1] = key;
		i++;
	}
	return (arr);
}

int	ft_find_min_id(int *arr, int i, int n)
{
	int	min_id;

	min_id = i;
	while (i < n)
	{
		if (arr[i] < arr[min_id])
			min_id = i;
		i++;
	}
	return (min_id);
}

int	*ft_selection_sort(int *arr, int n)
{
	int	i;
	int	min_id;
	int	temp;

	i = 0;
	while (i < (n - 1))
	{
		min_id = ft_find_min_id(arr, i, n);
		if (min_id != i)
		{
			temp = arr[i];
			arr[i] = arr[min_id];
			arr[min_id] = temp;
		}
		i++;
	}
	return (arr);
}

void	ft_print_array(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int	*arr;
	int	n;

	if (argc < 2)
		return (0);
	n = argc - 1;
	arr = create_array(argc, argv, n);
	if (!arr)
		return (1);
	arr = ft_selection_sort(arr, n);
	ft_print_array(arr, n);
	free(arr);
	return (0);
}
