# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lapuya-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 17:47:08 by lapuya-p          #+#    #+#              #
#    Updated: 2021/08/23 10:31:24 by ren              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./Libft/libft.a
NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_basic_cases.c \
	   ft_complex_cases.c \
	   ft_converters.c \

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
AR = ar rcs

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) lib
	$(AR) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) -c $(FLAGS) $(SRCS)

bonus: $(OBJS_B)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS_B)
	ar -rcs $(NAME) $(OBJS_B)

lib: 
	$(MAKE) -C ./libft
	cp Libft/libft.a $(NAME)


main:
	$(CC) $(FLAGS) $(SRCS)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
