/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:42:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/12 14:38:28 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	car;

	i = ft_strlen(s);
	car = (char)c;
	while (i >= 0)
	{
		if (s[i] == car)
			return ((char *)s + i);
		i--;
	}
	if (car == '\0')
		return ((char *)s + i);
	return (0);
}
