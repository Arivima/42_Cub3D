# Makefile

NAME				= cub3D

# Paths
LIB_DIR				= ./lib

LIBFT_DIR			= $(LIB_DIR)/libft
LIBFT_A				= $(LIBFT_DIR)/libft.a

# MLX_DIR				= $(LIB_DIR)/mlx/mlx
MLX_DIR				= $(LIB_DIR)/mlx/minilibx-linux
# MLX_DYLIB			= libmlx.dylib
MLX_A				= $(MLX_DIR)/libmlx_Linux.a

# LIB_A				= $(LIBFT_A) $(MLX_DYLIB) 
LIB_A				= $(LIBFT_A) $(MLX_A)
HEAD_DIR			= ./include

# Sources 
FILES				= \
						main.c\
						exit.c\
						error.c\

PARSING_FILES		= \
						init.c\
						init_map.c\
						parsing.c\
						parsing_arguments.c\
						parsing_map.c\
						checking_map.c\

PARSING				= $(addprefix parsing/, $(PARSING_FILES))

EXECUTION_FILES		= \
						execution.c\
						raycasting.c\
						raycasting_calc.c\
						draw_3D.c\
						draw_2D.c\
						texture.c\
						events_loop.c\
						events_events.c\
						events_reset.c\
						events_mouse.c\
						execution_bonus.c\
						files.c\
						files_gif.c\
						floor.c\
						sprite.c\
						levels1.c\
						render_sprite.c\
						render_sprite_aus.c\

EXECUTION			= $(addprefix execution/, $(EXECUTION_FILES))

UTILS_FILES			= \
						utils.c\
						utils_angles.c\
						utils_bres.c\
						utils_colors.c\
						utils_colors_trgb.c\
						utils_point.c\
						utils_sprite.c\

UTILS				= $(addprefix utils/, $(UTILS_FILES))

SRCS_DIR			=	./srcs
SRCS				= \
						$(addprefix $(SRCS_DIR)/,$(FILES))\
						$(addprefix $(SRCS_DIR)/,$(PARSING))\
						$(addprefix $(SRCS_DIR)/,$(EXECUTION))\
						$(addprefix $(SRCS_DIR)/,$(UTILS))\


# Objects 
OBJS_DIR			=	./objs
OBJS				= $(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS:.c=.o))

# Flags and libraries
INCLUDES			= -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(HEAD_DIR)
CFLAGS 				= -Wall -Wextra -Werror $(INCLUDES) -g #-fsanitize=address
# MLX_FLAGS			= $(MLX_DYLIB) -g -L $(MLX_DIR) -framework Metal -framework AppKit -F/Library/Frameworks
MLX_FLAGS			= $(MLX_A) -L $(MLX_DIR) -I $(MLX_DIR) -lXext -lX11 -lm -lz

# Colors
GREEN 				= \033[01;32m
RESET 				= \033[00m

# Rules
all:				$(NAME)

$(NAME):			libraries $(LIB_A) $(OBJS) 
					@gcc -g $(CFLAGS) $(OBJS) $(MLX_FLAGS)  $(LIB_A) -o $(NAME)
					@echo "$(GREEN)$(NAME) successfully compiled $(RESET)"

sanitize:			libraries $(LIB_A) $(OBJS) 
					@gcc -g -fsanitize=address $(CFLAGS) $(OBJS) $(MLX_FLAGS)  $(LIB_A) -o $(NAME)
					@echo "$(GREEN)$(NAME) successfully compiled $(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
					@mkdir -p $(@D)
					@gcc -c -g $(CFLAGS) $< -o $@

$(OBJS): 			| $(OBJS_DIR)

$(OBJS_DIR):
					@mkdir $(OBJS_DIR)

libraries:			
					@printf "Making libft..." && make -C $(LIBFT_DIR) && echo "$(GREEN)Libft successfully compiled $(RESET)"
					@printf "Making mlx..." && make -C $(MLX_DIR) && echo "$(GREEN)Mlx successfully compiled $(RESET)"
					# @mv $(MLX_DIR)/$(MLX_DYLIB) .
# this last line to be commented if on linux
clean:				
					@make clean -C $(LIBFT_DIR)
					@make clean -C $(MLX_DIR)
					@rm -f $(OBJS)
					@echo "$(GREEN)Successfully cleaned objects - $(NAME)$(RESET)"

fclean: 			clean
					@make fclean -C $(LIBFT_DIR)
					@make clean -C $(MLX_DIR)
					@rm -f $(OBJS)
					@rm -f $(NAME)
					@rm -f $(MLX_DYLIB)
					@rm -rf $(OBJS_DIR)
					@echo "$(GREEN)Successfully forced cleaned - $(NAME)$(RESET)"

bis:				
					@rm -f $(OBJS)
					@rm -f $(NAME)
					@rm -rf $(OBJS_DIR)
					@echo "$(GREEN)Successfully cleaned binary and objects  - $(NAME)$(RESET)"
					@make

run:				bis
					@say -v Amelie “Le projet Cube 3D a bien été compilé. Vous vous apprêtez à entrer dans le monde du conte de la princesse Ka gou ya”
					@./$(NAME) '/Users/avilla-m/Desktop/42_workspace/_Cub3D/maps/test.cub'


re: 				fclean all

norme:				
					norminette ./include ./srcs ./lib/libft | awk '! /OK!/'

.PHONY: 			all clean fclean re libraries bis run bonus norme
