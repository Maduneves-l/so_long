##########################################################
#					Instructions						 #
##########################################################

NAME =  so_long
BONUS_NAME = 
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address 
CC = cc 
UNAME := $(shell uname)

##########################################################
#					SOURCES AND OBJS					 #
##########################################################

SRCS = main.c check_map.c utils_map.c flood_fill.c

BONUS_SRCS = 

OBJS :=$(SRCS:.c=.o)

OBJS_BONUS :=$(BONUS_SRCS:.c=.o)


##########################################################
#					CODIGOS ANSI						 #
##########################################################


CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CLEARBLUE	= \033[1;94m
CYAN 		= \033[1;36m
PURPLE		= \033[1;35m
WHITE 		= \033[1;37m
BLACK 		= \033[1;30m
GREY 		= \033[0;37m

##########################################################

ifeq ($(UNAME), Darwin)
	MLX_LIB_DIR = minilibx_opengl/
	MLX_INCLUDE = -Iminilibx_opengl
	MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework AppKit -O3
else
	MLX_LIB_DIR = minilibx-linux
	MLX_INCLUDE = -Iminilibx-linux
	MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -O3
endif


all: $(NAME)

$(NAME) : $(OBJS)
	@make -C ./libft/ --silent --no-print-directory
	@make -C ./printf/ --silent --no-print-directory
	@make -C $(MLX_LIB_DIR) --silent --no-print-directory
	$(CC) $(CFLAGS) $(^) libft/libft.a printf/printf.a $(MLX_FLAGS) -o $(@)
	@clear
	@echo "$(GREEN)Compilation of ${CLR_RMV}${CYAN}$(NAME): ${CLR_RMV}$(GREEN)⭐️"
	@echo "$(CYAN)$(NAME) ${CLR_RMV}$(GREEN)created with sucess ${CLR_RMV} ✔️"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

bonus: 

clean:
	rm -f $(OBJS)
	make clean -C ./libft/
	make clean -C ./printf/
	clear
	@echo "$(RED)Deleting🗑 $(PURPLE)-> $(YELLOW)$(NAME) $(CLR_RMV)$(RED)[objs]$(GREEN) ✔️${CLR_RMV}"

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/
	make fclean -C ./printf/
	clear
	@echo "$(RED)Deleting🗑 $(PURPLE)-> $(YELLOW)$(NAME) $(CLR_RMV)$(RED)[objs] $(GREEN)✔️${CLR_RMV}"

re: fclean all

.PHONY: all clean fclean re
