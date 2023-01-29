/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:36:44 by araymond          #+#    #+#             */
/*   Updated: 2023/01/24 15:15:17 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(void *p, int *count)
{
	ft_putstr("0x");
	*count += 2;
	if (p == NULL)
	{
		ft_putchar('0');
		(*count)++;
		return ;
	}
	ft_hexadecimal((long long)p, 'x', count);
}

static char	*ft_assignbase(char c)
{
	char	*hexbase;

	if (c == 'X')
		hexbase = "0123456789ABCDEF";
	else
		hexbase = "0123456789abcdef";
	return (hexbase);
}

void	ft_hexadecimal(unsigned long n, char c, int *count)
{
	int		fullnum[LONG_NUMBER];
	char	*hexbase;
	int		i;

	if (n == 0)
	{
		ft_putchar('0');
		(*count)++;
		return ;
	}
	hexbase = ft_assignbase(c);
	i = 0;
	while (n)
	{
		fullnum[i] = n % 16;
		n /= 16;
		i++;
	}
	--i;
	while (i >= 0)
	{
		ft_putchar(hexbase[fullnum[i--]]);
		(*count)++;
	}
}
