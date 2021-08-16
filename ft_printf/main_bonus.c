/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:53:52 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/16 19:26:49 by lapuya-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf_bonus.h"

int	main(void)
{
	int	count;
	int	count_printf;

	count = 0;
	count_printf = 0;
	printf("------------------ chars con flag '-' -----------------\n");
	count = ft_printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ");
	printf("\n");
	count_printf= printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ");

	printf("\nLa cuenta de ft es: %d\n", count);
	printf("La cuenta de printf es: %d\n", count_printf);


	/*
	 * print(" %-3s %-4s ", " - ", ""));
	 * print(" %-2s %-3s %-4s %-5s ", " - ", "", "4", "")
	 * rint(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ")
	count_ft = 0;
	count_print = 0;
	printf("------------- CHAR CASE -----------------\n");
	count_ft = ft_printf("%c", 'h');
	printf("\n");
	count_print = printf("%c", 'h');
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
	printf("------------ STRING CASE ----------------\n");
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%s", "hoola");
	printf("\n");
	count_print = printf("%s", "hoola");
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
	printf("------------ POINTER CASE ---------------\n");
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%p", &a);
	printf("\n");
	count_print = printf("%p", &a);
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
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
	printf("--------- UNSIGNED DECIMAL CASE ----------\n");
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%u", -321321321);
	printf("\n");
	count_print = printf("%u", -321321321);
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
	printf("---------- HEXADECIMAL CASE -------------\n");
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%x", 321321);
	printf("\n");
	count_print = printf("%x", 321321);
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);
	printf("---------- PERCENTAGE CASE ---------------\n");
	count_ft = 0;
	count_print = 0;
	count_ft = ft_printf("%%");
	printf("\n");
	count_print = printf("%%");
	printf("\nLa cuenta de ft es: %d\n", count_ft);
	printf("La cuenta de printf es: %d\n", count_print);

	printf("--------------LEAKS----------------------\n");
	system("leaks output");*/
	return (0);
}
