/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 08:34:27 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/05/19 12:57:19 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_format
{
	int type;
	int minus;
	int zero;
	int dot;
	int asterisk;
	int counter;

}	t_format;

int	ft_printf(const char *format, ...);

#endif
