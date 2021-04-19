/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:02:48 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/04/19 13:32:42 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXT_LINE_UTILS_H
# define NEXT_LINE_UTILS_H
# define BUFFER_SIZE 32

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int	get_next_line(int fd, char **line);
char    *ft_strdup(const char *s1);
void    *ft_memcpy(void *dst, const void *src, size_t len);
size_t  ft_strlen(const char *str);


#endif