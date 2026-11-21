/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strnstr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mrayamma <mrayamma@student.42abudhabi.ae> #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 17:43:40 by mrayamma         #+#    #+#              */
/*   Updated: 2026/10/19 20:44:56 by mrayamma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char *) str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (to_find[j] != '\0' && str[i + j] == to_find[j] && (i + j) < len)
		{
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *) & str[i]);
		i++;
	}
	return (0);
}
