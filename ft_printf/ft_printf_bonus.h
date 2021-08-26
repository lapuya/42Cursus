/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:14:22 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/26 18:09:14 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

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

int		ft_printf(const char *format, ...);
int		ft_char_case(va_list params, t_format *flags);
int		ft_string_case(va_list params, t_format *flags);
int		ft_pointer_case(va_list params, t_format *flags);
int		ft_decimal_integer_case(va_list params, t_format *flags);
int		ft_udecimal_case(va_list params, t_format *flags);
int		ft_hexadecimal_case(char c, va_list params, t_format *flags);
int		ft_upper_hex_case(va_list params);
int		ft_percentage_case(t_format *flags);
int		ft_long_to_hex(size_t nbr);
int		ft_tohex(unsigned int nbr);
int		ft_to_uphex(unsigned int nbr);
void	ft_initialize_flags(t_format *f);
int		ft_process_flags(const char *str, int i, t_format *f);
int		ft_putformat(char c, int diff);
void	ft_putminus(t_format *f, int *count);
void	ft_putplus(t_format *f, int *count);
void	ft_putspace(t_format *f, int *count);
void	ft_put_hexsign(t_format *f, char c, int *count);

#endif
