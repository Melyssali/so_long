
# -- COLORS -- #
BLACK=\033[0;30m# Black
RED=\033[0;31m# Red
GREEN=\033[0;32m# GREEN
YELLOW=\033[0;33m# YELLOW
BLUE=\033[0;34m# BLUE
PURPLE=\033[0;35m# PURPLE
CYAN=\033[0;36m# CYAN
WHITE=\033[0m# WHITE

# ---------- VARIABLES  ---------- 
# Flags de compilation / ne pas oublier -Wall
CFLAGS = -Werror -Wextra -Wall -g -fsanitize=address -mmacosx-version-min=14.1
MLXFLAGS = -L./libs/MLX42/build -lmlx42 -I./libs/MLX42/include/MLX42 -framework Cocoa -framework OpenGL -framework IOKit
DEPS = ./include/so_long.h
NAME = so_long
# Commande pour archiver les fichiers objets (.o) en une bibliothèque statique
AR = ar rcs
RM = rm -rf
SRC_DIR = ./src/

SRC = $(SRC_DIR)main.c $(SRC_DIR)get_map.c $(SRC_DIR)check_map.c $(SRC_DIR)count.c $(SRC_DIR)game_init.c $(SRC_DIR)draw_map.c $(SRC_DIR)player_movement.c $(SRC_DIR)show_score.c
# SRC = $(SRC_DIR)check_map.c

# Chemin de mon autre library a utiliser
LIBFT_DIR = ./libs/Libft
MLX_DIR = ./libs/MLX42/build
PRINTF_DIR = ./libs/Libft/Printf
MLX_DIR_INCLUDE = ./libs/MLX42/include/MLX42


# Liste des fichiers objets .o, générée à partir de SRC
OBJ = $(SRC:.c=.o)

# ---------- REGLES MAKEFILE  ---------- 
all: mlx42-setup $(NAME)

mlx42-setup:
	echo "Cloning MLX42 repository..."
	cd ./libs && \
	git clone https://github.com/codam-coding-college/MLX42.git || (echo "MLX42 already cloned" && exit 0)
	@echo "Entering MLX42 directory..."
	cd ./libs/MLX42 && \
	cmake -B build && \
	cmake --build build -j4

sanitize: CFLAGS += -fsanitize=address
sanitize: all
leaks: all
	leaks --atExit -- ./$(NAME) ./maps/map2.ber

# Compile les fichiers objets et crée la bibliothèque
$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(OBJ) $(MLXFLAGS) $(CFLAGS) $(X11_FLAGS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME) -I/Users/mlesein/.brew/opt/glfw/include/GLFW -L/Users/mlesein/.brew/opt/glfw/lib -lglfw
	@echo "$(GREEN)Compilation successful. Library: $(NAME)$(WHITE)"

# Règle de modèle pour compiler chaque fichier .c en un fichier .o
%.o: %.c $(DEPS)
	@$(CC) -c -o $@ $< -I$(LIBFT_DIR) -I$(MLX_DIR_INCLUDE) -I$(PRINTF_DIR) $(CFLAGS)
	
# On met un @ pour mute dans le terminal, pour que ça ne s'affiche pas
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) $(OBJ)
	@echo "$(CYAN)Object files cleaned successfully. Library: $(NAME)$(WHITE)"
	@echo "--------------------------------------------------------"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) fclean
	@$(RM) $(NAME) $(OBJ)
	@echo "$(CYAN)Library cleaned successfully. Library: $(NAME)$(WHITE)"
	@echo "--------------------------------------------------------"

re: fclean all
.PHONY: all clean fclean re
