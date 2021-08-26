#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 17:47:08 by lapuya-p          #+#    #+#              #
#    Updated: 2021/08/23 18:41:41 by lapuya-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./Libft/libft.a
NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_basic_cases.c \
	   ft_complex_cases.c \
	   ft_converters.c 

SRCS_B = ft_printf_bonus.c \
		 ft_basic_cases_bonus.c \
		 ft_complex_cases_bonus.c \
		 ft_converters_bonus.c \
		 ft_flags_bonus.c \
		 ft_putsigns_bonus.c	


CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) lib
	$(AR) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) -c $(FLAGS) $(SRCS)

bonus: $(OBJS_B) lib
	$(AR) $(NAME) $(OBJS_B)

$(OBJS_B): $(SRCS_B)
	$(CC) -c $(FLAGS) $(SRCS_B)

lib: 
	$(MAKE) -C ./libft
	cp Libft/libft.a $(NAME)

main: all
	$(CC) -c main.c
	$(CC) main.o $(NAME)

main_bonus: bonus
			$(CC) -c main_bonus.c
			$(CC) main_bonus.o $(NAME)

clean: 
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean bonus re lib
