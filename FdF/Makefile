# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lapuya-p <lapuya-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 12:21:10 by lapuya-p          #+#    #+#              #
#    Updated: 2021/09/02 10:40:12 by lapuya-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./Libft/libft.a
LIBX = ./minilibx_macos/libmlx.a
NAME = fdf

SRCS = fdf.c \
	   get_next_line.c \
	   ft_loaders.c	\
	   ft_draw.c

CC = gcc
FRAMEWORKS= -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./Libft
	$(MAKE) -C ./minilibx_macos/ all
	$(CC) $(SRC) -o $(NAME) $(FLAGS) $(SRCS) $(LIBFT) $(LIBX) $(FRAMEWORKS)

lib:
	$(MAKE) -C ./libft
	cp Libft/libft.a $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx_macos
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)
	rm -rf $(LIBX)

re: fclean all

.PHONY:	all clean fclean bonus re lib
