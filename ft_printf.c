/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:44:01 by araymond          #+#    #+#             */
/*   Updated: 2023/01/24 11:41:11 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_percentthree(const char *str, va_list *va, int *i, int *count)
{
	char	*new;

	if (*str == '%')
	{
		ft_putchar('%');
		(*count)++;
	}
	else if (*str == 'x' || *str == 'X')
	{
		ft_hexadecimal(va_arg(*va, unsigned int), *str, count);
	}
	else if (*str == 'u')
	{
		new = ft_long_itoa(va_arg(*va, unsigned int));
		ft_putstr(new);
		*count += ft_strlen(new);
		free(new);
	}
	else if (*str == 'p')
		ft_pointer(va_arg(*va, void *), count);
	(*i)++;
}

static void	ft_percenttwo(const char *str, va_list *va, int *i, int *count)
{
	char	*new;

	if (*str == 's')
	{
		new = va_arg(*va, void *);
		if (new == NULL)
			new = "(null)";
		ft_putstr(new);
		*count += ft_strlen(new);
		(*i)++;
	}
	else if (*str == 'i' || *str == 'd')
	{
		new = ft_itoa(va_arg(*va, int));
		ft_putstr(new);
		*count += ft_strlen(new);
		free(new);
		(*i)++;
	}
}

static void	ft_percentdetected(const char *str, va_list *va, int *i, int *count)
{
	while (*str)
	{
		if (*str == 'c')
		{
			ft_putchar(va_arg(*va, int));
			(*count)++;
			(*i)++;
		}
		else if (*str == 's' || *str == 'i' || *str == 'd')
			ft_percenttwo(str, va, i, count);
		else if (*str == '%' || *str == 'x' || *str == 'X' || *str == 'u'
			|| *str == 'p')
			ft_percentthree(str, va, i, count);
		break ;
	}
}

static void	ft_write(const char *str, int *i, int *count)
{
	ft_putchar(str[*i]);
	(*i)++;
	(*count)++;
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's'
				|| str[i + 1] == 'p' || str[i + 1] == 'd' || str[i + 1] == 'i'
				|| str[i + 1] == 'u' || str[i + 1] == 'x' || str[i + 1] == 'X'
				|| str[i + 1] == '%'))
		{
			i++;
			ft_percentdetected(&str[i], &va, &i, &count);
		}
		else
			ft_write(str, &i, &count);
	}
	va_end(va);
	return (count);
}
