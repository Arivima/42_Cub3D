NAME				= fdf
BONUS_NAME			= fdf_bonus

LIB_DIR				= ./lib
LIBFT_DIR			= $(LIB_DIR)/libft
LIBFT_A				= $(LIBFT_DIR)/libft.a
MLX_DIR				= $(LIB_DIR)/mlx
MLX_DYLIB			= libmlx.dylib
PRINTF_DIR			= $(LIB_DIR)/ft_printf
PRINTF_A			= $(PRINTF_DIR)/libftprintf.a
LIB_A				= $(LIBFT_A) $(PRINTF_A) $(MLX_DYLIB)

HEAD_DIR			= ./include

FILES				= \
						main.c\
						1_init.c\
						2_parsing_1.c\
						2_parsing_2.c\
						3_pixel_manipulation_1.c\
						3_pixel_manipulation_2_bonus.c\
						3_pixel_manipulation_3_bonus.c\
						4_draw_1.c\
						4_draw_2.c\
						5_draw_utils.c\
						5_draw_utils_colors_1.c\
						5_draw_utils_colors_2.c\
						6_events.c\
						7_utils_1.c\
						7_utils_2.c\
						8_exit.c\
						# _delete.c\
						# _testing.c\

SRCS_DIR			=	./srcs
SRCS				= $(addprefix $(SRCS_DIR)/,$(FILES))

OBJS_DIR			=	./objs
OBJS				= $(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS:.c=.o))

INCLUDES			= -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(PRINTF_DIR) -I $(HEAD_DIR)
CFLAGS 				= -Wall -Wextra -Werror $(INCLUDES) -g
MLX_FLAGS			= $(MLX_DYLIB) -g -L $(MLX_DIR) -framework Metal -framework AppKit -F/Library/Frameworks

GREEN 				= \033[01;32m
RESET 				= \033[00m

all:				$(NAME)

$(NAME):			libraries $(LIB_A) $(OBJS) 
					@gcc -g $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIB_A) -o $(NAME)
					@echo "$(GREEN)FDF successfully compiled $(RESET)"

$(BONUS_NAME):		libraries $(LIB_A) $(OBJS) 
					@gcc -g $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIB_A) -o $(NAME)
					@echo "$(GREEN)FDF successfully compiled $(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
					@mkdir -p $(@D)
					@gcc -c -g $(CFLAGS) $< -o $@

$(OBJS): 			| $(OBJS_DIR)

$(OBJS_DIR):
					@mkdir $(OBJS_DIR)

bonus :				$(BONUS_NAME)

libraries:			
					@printf "Making libft..." && make -C $(LIBFT_DIR) && echo "$(GREEN)Libft successfully compiled $(RESET)"
					@printf "Making printf..." && make -C $(PRINTF_DIR) && echo "$(GREEN)Printf successfully compiled $(RESET)"
					@printf "Making mlx..." && make -C $(MLX_DIR) && echo "$(GREEN)Mlx successfully compiled $(RESET)"
					@mv $(MLX_DIR)/$(MLX_DYLIB) .

clean:				
					@make clean -C $(LIBFT_DIR)
					@make clean -C $(PRINTF_DIR)
					@make clean -C $(MLX_DIR)
					@rm -f $(OBJS)
					@echo "$(GREEN)Successfully cleaned $(RESET)"

fclean: 			clean
					@make fclean -C $(LIBFT_DIR)
					@make fclean -C $(PRINTF_DIR)
					@rm -f $(NAME)
					@rm -f $(BONUS_NAME)
					@rm -f $(MLX_DYLIB)
					@rm -r $(OBJS_DIR)
					@echo "$(GREEN)Successfully f-cleaned $(RESET)"

bis:				
					@rm -f $(OBJS)
					@echo "$(GREEN)Successfully cleaned objects $(RESET)"
					@make


re: 				fclean all
.PHONY: 			all clean fclean re libraries bis bonus
