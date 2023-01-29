/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:37:24 by araymond          #+#    #+#             */
/*   Updated: 2023/01/25 11:51:06 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define LONG_NUMBER 21

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_long_itoa(long a);
void	ft_hexadecimal(unsigned long n, char c, int *count);
void	ft_pointer(void *p, int *count);
int		ft_printf(const char *str, ...);

#endif