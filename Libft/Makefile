# declaration of variables
NAME = libft.a

SRCS = main.c ft_memmove.c 

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra





all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)


$(OBJS): $(SRCS)
	gcc $(FLAGS) $(SRCS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all