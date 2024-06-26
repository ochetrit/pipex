SRCS = main.c parsing.c utils.c pipex.c heredoc.c

OBJS = $(SRCS:.c=.o) ./libft/libft.a

NAME = pipex

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Werror -Wextra -g3
LDFLAGS = -L./libft -lft

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

$(NAME): $(OBJS)
		$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)
			@echo "                 +---------------------+\n \
                |  $(YELLOW) PIPEX $(GREEN)[OK]$(NC)        |\n \
			 +---------------------+"

$(LIBFT):
	make -C ./libft

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean
	make all

.PHONY: all clean fclean re