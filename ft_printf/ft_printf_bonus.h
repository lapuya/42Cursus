/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:14:22 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/22 23:23:25 by ren              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

//#include "Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct s_flags
{
	int	minus;
	int	zeros;
	int	dot;
	int	precision;
	int	width;
	int	sharp;
	int	space;
	int	plus;
}	t_format;

int	ft_printf(const char *format, ...);
int	ft_char_case(va_list params, t_format *flags);
int	ft_string_case(va_list params, t_format *flags);
int	ft_pointer_case(va_list params, t_format *flags);
int	ft_decimal_integer_case(va_list params, t_format *flags);
int	ft_udecimal_case(va_list params, t_format *flags);
int ft_hexadecimal_case(char c, va_list params, t_format *flags);
int	ft_upper_hex_case(va_list params);
int	ft_percentage_case(void);
int	ft_long_to_hex(size_t nbr);
int	ft_tohex(unsigned int nbr);
int	ft_to_uphex(unsigned int nbr);
int	ft_determine_size(long n);
int	ft_determine_usize(unsigned int n);
void	ft_initialize_flags(t_format *f);
int	ft_process_flags(const char *str, int i, t_format *f);
int	ft_putformat(char c, int diff);
int	ft_ptrlen(size_t nbr);
int	ft_nbrlen(long nbr);

//temporal de libft
void	ft_putchar(int c);
int	ft_itoa_2(long n);
int	ft_uitoa(unsigned int n);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
int	ft_putstr(char *s, int len);
size_t	ft_strlen(const char *str);

#endif
