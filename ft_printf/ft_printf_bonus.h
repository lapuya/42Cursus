/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:14:22 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/16 19:21:32 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

//#include "Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_flags
{
	int	minus;
	int	zeros;
	int	precision;
	int	width;
}	t_format;

int	ft_printf(const char *format, ...);
int	ft_char_case(va_list params, t_format *flags);
int	ft_string_case(va_list params, t_format *flags);
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
void	ft_initialize_flags(t_format *f);
int	ft_process_flags(const char *str, int i, t_format *f);

//temporal de libft
void	ft_putchar(int c);
int	ft_itoa_2(int n);
int	ft_uitoa(unsigned int n);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
int	ft_putstr(char *s, int len);
size_t	ft_strlen(const char *str);

#endif
