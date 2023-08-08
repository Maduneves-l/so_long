NAME = printf.a

SRCS =  ft_printf.c ft_putaddress.c ft_putchar.c \
		ft_puthex.c ft_putnbr.c ft_putstr.c ft_unsgint.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c 
		

OBJS :=$(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS)
	ar -crs $@ $^

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all