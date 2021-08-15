/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:53:52 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/15 11:28:50 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	a;
	int	*b;
	int	count_ft;
	int	count_print;

	a = 10;
	b = &a;
	count_ft = 0;
	count_print = 0;
	system("clear");
	sleep(1);
	printf("This will execute the ft_printf function.");
	printf("\nIt will compare the execution of a given case and then it will print how many characters have been printed\n");
	printf("Finally, it will show if there are leaks in the program\n");
	sleep(2);
	printf("------------- CHAR CASE -----------------\n");
	count_ft = ft_printf("%c", 'h');
	printf("\n");
	count_print = printf("%c", 'h');
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
	sleep(2);
	printf("------------ STRING CASE ----------------\n");
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%s", "hoola");
	printf("\n");
	count_print = printf("%s", "hoola");
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
	sleep(2);
	printf("------------ POINTER CASE ---------------\n");
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%p", &a);
	printf("\n");
	count_print = printf("%p", &a);
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
	sleep(2);
	printf("---------- DECIMAL-INTEGER CASE ----------\n");
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%d", -123);
	printf("\n");
	count_print = printf("%d", -123);
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%i", 12341234);
	printf("\n");
	count_print = printf("%i", 12341234);
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
	sleep(2);
	printf("--------- UNSIGNED DECIMAL CASE ----------\n");
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%u", -321321321);
	printf("\n");
	count_print = printf("%u", -321321321);
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
	sleep(2);
	printf("---------- HEXADECIMAL CASE -------------\n");
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%x", 321321);
	printf("\n");
	count_print = printf("%x", 321321);
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
	sleep(2);
	printf("---------- PERCENTAGE CASE ---------------\n");
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%%");
	printf("\n");
	count_print = printf("%%");
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);

	printf("--------------LEAKS----------------------\n");
	sleep(2);
	system("leaks output");
	return (0);
}
