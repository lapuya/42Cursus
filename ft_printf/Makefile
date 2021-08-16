# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 17:47:08 by lapuya-p          #+#    #+#              #
#    Updated: 2021/08/16 18:35:00 by lapuya-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a
NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_basic_cases.c \
	   ft_complex_cases.c \
	   ft_auxiliaries.c \
	   ft_converters.c \
	   main.c

SRCS_B = ft_printf_bonus.c \
		 ft_auxiliares_bonus.c \
		 ft_auxiliaries_bonus.c \
		 ft_basic_cases_bonus.c \
		 ft_complex_cases_bonus.c \
		 ft_converters_bonus.c \
		 ft_flags_bonus.c \
		 main_bonus.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) -o output $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS_B)
	$(CC) -o output_bonus $(FLAGS) $(SRCS_B)
	ar -rcs $(NAME) $(OBJS_B)


all: $(NAME)


main:
	$(CC) $(FLAGS) $(SRCS)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
