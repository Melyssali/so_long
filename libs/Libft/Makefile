
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
# Flags de compilation
CFLAGS = -Werror -Wextra -Wall
DEPS = libft.h
NAME = libft.a
# Commande pour archiver les fichiers objets (.o) en une bibliothèque statique
AR = ar rcs
RM = rm -rf

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c

# Chemin de mon Printf
PRINTF_DIR = ./Printf

# Liste des fichiers objets .o, générée à partir de SRC
OBJ = $(SRC:.c=.o)

# ---------- REGLES MAKEFILE  ---------- 
all: $(NAME)

# Compile les fichiers objets et crée la bibliothèque
$(NAME): $(OBJ)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)Compilation successful. Library: $(NAME)$(WHITE)"

# Règle de modèle pour compiler chaque fichier .c en un fichier .o
%.o: %.c $(DEPS)
	@$(CC) -c -o $@ $< -I$(PRINTF_DIR) $(CFLAGS)

# On met un @ pour mute dans le terminal, pour que ça ne s'affiche pas
clean:
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(RM) $(OBJ)
	@echo "$(CYAN)Object files cleaned successfully. Library: $(NAME)$(WHITE)"
	@echo "--------------------------------------------------------"

fclean: clean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(CYAN)Library cleaned successfully. Library: $(NAME)$(WHITE)"
	@echo "--------------------------------------------------------"

re: fclean all
.PHONY: all clean fclean re



