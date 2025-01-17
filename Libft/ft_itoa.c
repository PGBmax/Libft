/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:02:18 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/25 11:56:55 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	count = count + 2;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_intlen(n);
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	str[len - 1] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (--len > 0 && str[len - 1] != '-')
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
