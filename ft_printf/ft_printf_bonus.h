/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:14:22 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/15 12:21:05 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//#include "Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_char_case(va_list params);
int	ft_string_case(va_list params);
int	ft_pointer_case(va_list params);
int	ft_decimal_integer_case(va_list params);
int	ft_udecimal_case(va_list params);
int ft_hexadecimal_case(va_list params);
int	ft_upper_hex_case(va_list params);
int	ft_percentage_case(void);
int	ft_long_to_hex(unsigned long nbr);
int	ft_tohex(unsigned int nbr);
int	ft_to_uphex(unsigned int nbr);
int	ft_determine_size(long n);
int	ft_determine_usize(unsigned int n);

//temporal de libft
void	ft_putchar(int c);
int	ft_itoa_2(int n);
int	ft_uitoa(unsigned int n);

#endif
