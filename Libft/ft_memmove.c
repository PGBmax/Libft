/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:21:54 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/26 16:46:38 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*strdest;
	unsigned char	*strsrc;

	if (!dest && !src)
		return (NULL);
	strdest = (unsigned char *) dest;
	strsrc = (unsigned char *) src;
	i = 0;
	if (dest >= src)
	{
		while (n-- > 0)
			strdest[n] = strsrc[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
