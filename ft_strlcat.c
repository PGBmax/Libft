/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:55:51 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/12 15:03:34 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_l;
	size_t	src_l;

	src_l = ft_strlen(src);
	dest_l = ft_strlen(dst);
	i = 0;
	if (dest_l < size - 1 && size > 0)
	{
		while (src[i] && dest_l + i < size - 1)
		{
			dst[dest_l + i] = src[i];
			i++;
		}
		dst[dest_l + i] = 0;
	}
	if (dest_l >= size)
		dest_l = size;
	return (dest_l + src_l);
}
