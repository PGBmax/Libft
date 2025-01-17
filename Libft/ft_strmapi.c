/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:21:13 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/25 12:08:04 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = ft_calloc(sizeof(char), (i + 1));
	if (!str)
		return (NULL);
	while (i--)
		str[i] = f(i, s[i]);
	return (str);
}
