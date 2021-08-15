/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:06:28 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/05/18 13:34:19 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line = NULL;
    int i = 6;
    fd = open("example1.txt", O_RDONLY);
    printf("%d\n", fd);
    if (fd > 0)
    {
        printf("Archivo abierto correctamente\n");
        printf("\n");
        while (i)
        {
            printf("RESULTADO FUNCION: %d\n", get_next_line(fd, &line));
            printf("LINE: %s$$\n", line);
            free(line);
            line = NULL;
            i--;
        }
        /// system("leaks a.out");
    }
    return (0);
}