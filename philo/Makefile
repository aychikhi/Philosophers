NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

SRCS = philo.c philo_routine.c philo_utils.c philo_utils1.c philo_routine_utils.c parser.c init_fun.c ./utils/ft_atoi.c ./utils/ft_isdigit.c ./utils/ft_isspace.c\
		 ./utils/ft_putchar_fd.c ./utils/ft_putstr_fd.c ./utils/ft_putendl_fd.c ./utils/ft_strcmp.c\

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) philo.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean