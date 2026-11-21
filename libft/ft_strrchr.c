/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strrchr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mrayamma <mrayamma@student.42abudhabi.ae> #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/16 19:07:07 by mrayamma         #+#    #+#              */
/*   Updated: 2026/11/05 20:11:43 by mrayamma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	while (l >= 0)
	{
		if (s[l] == (char) c)
			return ((char *) & s[l]);
		l--;
	}
	return (NULL);
}
