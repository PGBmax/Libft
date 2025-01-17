/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:10:24 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/25 11:59:24 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cha;
	size_t			i;

	cha = c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == cha)
			return (&str[i]);
		i++;
	}
	return (0);
}
