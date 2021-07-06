/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 08:34:27 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/07/06 12:43:06 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_flags
{
	int minus;
	int zero;
	int precision;
	int width;
	int counter;
} t_flags;

typedef struct s_format
{
	t_flags flags;
	int has_flags;
	int type;
}	t_format;

int	ft_printf(const char *format, ...);
void	ft_setflag(t_flags *f, char c);
void	ft_initialize_format(t_format *f);
void	ft_initialize_flags(t_flags *f);
int	ft_parse_format(t_format *style, char *format);
int		ft_processflags(t_flags *flag, const char *format, int *count);
int	ft_isdigit(int c);
void ft_putchar(char c);

#endif
