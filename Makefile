NAME 		= fdf
MLX 		= libmlx_Linux.a
LIBFT 		= libft.a


PRINTF_PATH = ./ft_printf/
LFT_PATH 	= ./libft/
MLX_PATH 	= ./mlx_linux/
INCLUDES 	= ./includes
SRCDIR 		= ./src/

SRC 		= $(SRCDIR)main.c \
			$(SRCDIR)convert_file.c \
			$(SRCDIR)draw.c \
			$(SRCDIR)close.c \
			$(SRCDIR)init.c \
			$(SRCDIR)map_utils.c \
			$(SRCDIR)utils.c \
			$(SRCDIR)key_hook.c \
			$(SRCDIR)mlx_image.c \
			$(SRCDIR)instructions.c \


OBJ= $(notdir $(SRC:.c=.o))
#OBJ= fdf.o

#compilation
CF 			= -Wall -Wextra -Werror
CC 			= cc
MLX_CF 		= -lm -lbsd -lmlx -lXext -lX11
CFI 		= -I$(INCLUDES)
LEAKS 		= valgrind
LEAKS_FILE	= valgrind-out.txt
LF 			= --leak-check=full \
        		--show-leak-kinds=all \
        		--track-origins=yes \
        		--verbose \
        		--log-file=$(LEAKS_FILE) \
        		./fdf maps/42.fdf 


#common commands
RM =rm -f

#rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@printf "\n$(CY)Generating FdF executable...$(RC)\n"
	@$(CC) $(CF) -o $(NAME) $(OBJ) -L $(LFT_PATH) -lft $(MLX_CF)
	@printf "$(GR)Done!$(RC)\n\n"

$(OBJ): $(SRC)
	@printf "\n$(CY)Compiling source files...$(RC)\n"
	@$(CC) $(CF) -g -c -I ./includes/ $(SRC)
	@printf "$(GR)Objects ready!$(RC)\n\n"

$(LIBFT):
	@printf "\n$(GR)Generating Libft...$(RC)\n"
	@make -C $(LFT_PATH)
	@printf "$(GR)Libft created!$(RC)\n\n"

bonus: all

re: fclean all

rebonus: fclean bonus

leaks: 
	$(LEAKS) $(LF)
	@printf "$(GR)Leaks log ready! Check valgrind-out.txt $(RC)\n\n"

cleanleaks: 
	$(RM) $(LEAKS_FILE)
	@printf "$(GR)Leaks log file deleted.$(RC)\n\n"

clean:
	@printf "\n$(YE)Cleaning all object files from libft...$(RC)\n"
	@make clean -C $(LFT_PATH)
	@printf "$(GR)Libft objects removed!$(RC)\n\n"
	$(RM) -rf $(OBJ) $(BONUS_OBJ) objs/

fclean: clean
	@printf "\n$(YE)Cleaning all additional objects and libraries...$(RC)\n"
	$(RM) -rf $(NAME) $(BONUS_OBJ) objs/
	@make fclean -C $(LFT_PATH)
	@printf "$(GR)All libraries removed!$(RC)\n\n"
	make cleanleaks

install: 
	sudo apt-get install gcc make xorg libxext-dev libbsd-dev -y
	@printf "$(GR)All dependencies ready!$(RC)\n\n"

.PHONY: clean fclean re rebonus all bonus

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m