LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(LIBFT_DIR)/include -I$(MLX_DIR) -Iinclude

SRC_DIR = src
BUILD_DIR = build

SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

NAME = fractol

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME) \
		-L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz \
		-o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(BUILD_DIR)
	rm -f $(OBJ_FILES)

fclean:	clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re