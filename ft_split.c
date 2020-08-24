/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:31:53 by Kwillum           #+#    #+#             */
/*   Updated: 2020/08/24 21:05:52 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cleaner(char **ptr, int iter)
{
	char	**tmp;

	tmp = ptr;
	while (iter--)
		free(*ptr++);
	free(tmp);
}

static int	count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		while (*s && *s != c)
			s++;
		words++;
	}
	return (words);
}

static int	add_words(char **ptr, char const *s, char c)
{
	char	*st;
	size_t	iter;
	char	**tmp;

	iter = 0;
	tmp = ptr;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		st = (char *)s;
		while (*s && *s != c)
			s++;
		iter++;
		if (!(*ptr++ = ft_substr(st, 0, s - st)))
		{
			cleaner(tmp, iter);
			return (0);
		}
	}
	*ptr = NULL;
	return (1);
}

char		**ft_split(char const *s, char c)
{
	size_t	n;
	char	**words;

	if (!s)
		return (NULL);
	n = count_words(s, c);
	if (!(words = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	if (!add_words(words, s, c))
	{
		free(words);
		return (NULL);
	}
	return (words);
}
