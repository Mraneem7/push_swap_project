/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrayamma <mrayamma@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:37:49 by mrayamma          #+#    #+#             */
/*   Updated: 2026/10/25 12:48:34 by mrayamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**free_split(char **sp, size_t i)
{
	while (i > 0)
	{
		i--;
		free(sp[i]);
	}
	free(sp);
	return (NULL);
}

static char const	*find_next_word(char const *s, char c, size_t *len)
{
	while (*s && *s == c)
	{
		s++;
	}
	if (!*s)
	{
		return (NULL);
	}
	*len = 0;
	while (s[*len] && s[*len] != c)
	{
		(*len)++;
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	**ptr;
	size_t	len;

	if (!s)
		return (NULL);
	split = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (NULL);
	ptr = split;
	s = find_next_word(s, c, &len);
	while (s)
	{
		*ptr = ft_substr(s, 0, len);
		if (!*ptr)
			return (free_split(split, ptr - split));
		ptr++;
		s = find_next_word(s + len, c, &len);
	}
	*ptr = NULL;
	return (split);
}
