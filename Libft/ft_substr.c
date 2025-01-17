/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:30:17 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/25 12:12:27 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (i == start)
		{
			while (j < len && s[i])
			{
				i++;
				j++;
			}
			break ;
		}
		i++;
	}
	return (j + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	int				count;
	unsigned int	i;
	size_t			j;

	count = ft_count(s, start, len);
	str = ft_calloc(count, 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i == start)
		{
			while (j < len && s[i])
				str[j++] = s[i++];
			break ;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
