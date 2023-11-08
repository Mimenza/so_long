/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:55:24 by emimenza          #+#    #+#             */
/*   Updated: 2023/10/23 08:12:45 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_to_base(unsigned int num, char *base, int *length)
{
	size_t	len;

	if (num < 0)
	{
		num = -num;
		ft_printchar('-', length);
	}
	len = ft_len(base);
	if (num >= len)
	{
		ft_to_base(num / len, base, length);
		ft_to_base(num % len, base, length);
	}
	else
		ft_printchar(base[num], length);
}
