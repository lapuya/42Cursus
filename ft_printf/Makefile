# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 17:47:08 by lapuya-p          #+#    #+#              #
#    Updated: 2021/08/15 12:53:15 by lapuya-p         ###   ########.fr        #
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

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) -o output $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

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
