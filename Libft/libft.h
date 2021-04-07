/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:17:56 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/07 12:05:16 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

void	ft_bzero(void *s, int n);
int	ft_strlen(char *str);
void	*ft_memset(void *b, int c, int n);
void	*memcpy(void *dst, const void *src, int n);
void	*memccpy(void dst, const void *src, int c, int n);


#endif