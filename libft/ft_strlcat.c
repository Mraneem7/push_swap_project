/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strlcat.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mrayamma <mrayamma@student.42abudhabi.ae> #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/16 17:16:08 by mrayamma         #+#    #+#              */
/*   Updated: 2026/10/16 17:46:34 by mrayamma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = 0;
	s_len = 0;
	i = 0;
	while ((dst[d_len] != '\0') && (d_len < size))
		d_len++;
	while (src[s_len] != '\0')
		s_len++;
	if (size <= d_len)
		return (size + s_len);
	while ((src[i] != '\0') && ((d_len + i) < (size - 1)))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
