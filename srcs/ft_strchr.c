/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:18:35 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/13 16:09:40 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	car;

	i = 0;
	car = (char)c;
	while (s[i])
	{
		if (s[i] == car)
			return ((char *)s + i);
		i++;
	}
	if (car == '\0')
		return ((char *)s + i);
	return (0);
}
