/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:33:52 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/10 15:11:07 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_have_len(const char *s1, const char *set, int verif)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	if (verif == 0)
	{
		while (i < len)
		{
			if (ft_strchr(set, s1[i]) == 0)
				break ;
			i++;
		}
		return (i);
	}
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = ft_have_len(s1, set, 0);
	j = ft_have_len(s1, set, 1);
	if (i >= j)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + i, j - i + 1);
	return (str);
}
