SRCS =	ft_atoi.c		\
	ft_isascii.c	\
	ft_isalnum.c	\
	ft_isalpha.c	\
	ft_isdigit.c	\
	ft_isprint.c	\
	ft_split.c		\
	ft_strjoin.c	\
	ft_strdup.c	\
	ft_strlcpy.c	\
	ft_strlcat.c	\
	ft_strlen.c	\
	ft_strnstr.c	\
	ft_tolower.c	\
	ft_toupper.c	\
	ft_itoa.c		\
	ft_memcmp.c	\
	ft_memcpy.c	\
	ft_putstr_fd.c	\
	ft_putchar_fd.c	\
	ft_putnbr_fd.c	\
	ft_calloc.c	\
	ft_putendl_fd.c	\
	ft_strncmp.c	\
	ft_bzero.c		\
	ft_strchr.c	\
	ft_strrchr.c	\
	ft_memmove.c	\
	ft_memset.c	\
	ft_memchr.c	\
	ft_substr.c	\
	ft_strmapi.c	\
	ft_striteri.c	\
	ft_strtrim.c	\
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
	get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	printf/ft_format.c printf/ft_printf.c printf/ft_write.c\
    ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
    ft_lstiter.c ft_lstmap.c

OBJS = ${SRCS:.c=.o} 

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)
		@echo "                 +---------------------+\n \
        	 |  $(YELLOW) LIBFT $(GREEN)[OK]$(NC)        |\n \
        	 +---------------------+"

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all:  ${NAME}
	ar -rcs $(NAME) $(OBJS)
		
clean:
		${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
			${RM} ${NAME}
			@echo " ${NAME} have been deleted"

re:	fclean all

.PHONY: all clean fclean re bonus
