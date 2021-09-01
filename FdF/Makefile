# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 12:21:10 by lapuya-p          #+#    #+#              #
#    Updated: 2021/09/01 14:19:48 by lapuya-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./Libft/libft.a
NAME = fdf

SRCS = fdf.c \
	   get_next_line.c \
	   ft_loaders.c 

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJS = $(SRCS:.c=.o)

all:	
	$(MAKE) -C ./Libft
	$(CC) $(SRC) -o $(NAME) $(FLAGS) $(SRCS) $(LIBFT)

lib:
	$(MAKE) -C ./libft
	cp Libft/libft.a $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean bonus re lib
