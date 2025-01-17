/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:44:25 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/10 12:44:25 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	j;
	char	last;

	last = c;
	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (last == c && str[i] != c)
			j++;
		last = str[i];
		i++;
	}
	return (j);
}

static char	**free_all(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split[i]);
	free(split);
	return (NULL);
}

static char	**ft_splited_split(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	j = 0;
	while (j < count_words(s, c) && s[i] != 0)
	{
		while (s[i] == c)
			i++;
		k = 0;
		while (s[i + k] != 0 && s[i + k] != c)
			k++;
		split[j] = malloc((k + 1) * sizeof(char));
		if (!split[j])
			return (free_all(split));
		l = 0;
		while (l < k)
			split[j][l++] = s[i++];
		split[j][l] = 0;
		j++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	else
		return (ft_splited_split(s, c, split));
}
