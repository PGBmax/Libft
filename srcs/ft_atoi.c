/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:36:45 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/09 16:24:35 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	temp;
	int	negatif;

	i = 0;
	temp = 0;
	negatif = 0;
	while (((nptr[i] >= 9 && nptr[i] <= 13)
			|| nptr[i] == 32) && nptr[i] != '\0')
		i++;
	if ((nptr[i] == 43 || nptr[i] == 45) && nptr[i] != '\0')
	{
		if (nptr[i] == 45)
			negatif++;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		temp = 10 * temp + (nptr[i] - '0');
		i++;
	}
	if (negatif % 2 == 1)
		temp = -temp;
	return (temp);
}
