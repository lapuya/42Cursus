/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:14:37 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/07/07 14:07:42 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_flags
{
	int minus;
	int zero;
	int dot;
	int asterisk;
	int precision;
	int width;
} t_flags;

typedef struct s_format
{
	t_flags flags;
	int has_flags;
	int type;
} t_format;

void	ft_initialize_format(t_format *f);
void	ft_initialize_flags(t_flags *f);
int		ft_is_flag(char c);
int		ft_is_type(char c);
void	ft_set_flag(t_flags *f, char c);
int	ft_char_case(va_list params, t_flags f);
void	ft_flag_digit(t_flags *f, char c);

#endif
