/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:53:52 by lapuya-p          #+#    #+#             */
/*   Updated: 2021/08/22 21:36:52 by ren              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf_bonus.h"

int	main(void)
{
	int	count;
	int	count_printf;
	int *a = NULL;

	count = 0;
	count_printf = 0;
	printf("------------------ chars con flag '-' -----------------\n");
	count = ft_printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ");
	printf("\n");
	count_printf= printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ");

	printf("\nLa cuenta de ft es: %d\n", count);
	printf("La cuenta de printf es: %d\n", count_printf);
	printf("---------------- pointers '-'---------------------- \n");
	count = ft_printf(" %-4p ", a);
	printf("\n");
	count_printf = printf(" %-4p ", a);
	printf("\nLa cuenta de ft es: %d\n", count);
	printf("La cuenta de printf es: %d\n", count_printf);
//	[200~TEST(26, print(" %-9p %-10p ", LONG_MIN, LONG_MAX))
	printf("--------------- d with '-' -----------------------\n");
	count = ft_printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n");
	count_printf = printf(" %-2u ", -1);
	printf("\nLa cuenta de ft es: %d\n", count);
	printf("La cuenta de printf es: %d\n", count_printf);
	printf("-------------- x with '-' --------------------------\n");
	count = ft_printf(" %-1x ", 0);
	printf("\n");
	count_printf = printf(" %-1x ", 0);
	printf("\nla cuenta de ft es: %d\n", count);
	printf("La cuenta de printf es: %d\n", count_printf);
	printf("---------------\n");
	count = ft_printf(" %-12x ", LONG_MIN);
	printf("\n");
	count_printf = printf(" %-2x ", 123321321);
	printf("\nla cuenta de ft es: %d\n", count);
	printf("La cuenta de printf es: %d\n", count_printf);

	printf("-------------- d with '0' ------------------------\n");
	count = ft_printf(" %04d ", 9);
	printf("\n");
	count_printf = printf(" %04d ", 9);
	printf("\nla cuenta de ft es: %d\n", count);
	printf("La cuenta de printf es: %d\n", count_printf);
	printf("---------------\n");
	printf(" %#x ", -1);

	printf("\n------- pruebas -----\n");
	unsigned long x = -1;
	printf("%ld\n", x);

	ft_printf(" %04d ", -14);
	printf("\n");



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
