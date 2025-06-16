NAME = test_map

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Chemins des dossiers
PARSING_DIR = parsing_map/
LIBFT_DIR = libft/
PRINTF_DIR = ft_printf/
GNL_DIR = get_next_line/

# Sources
SRCS =	$(PARSING_DIR)flood_fill.c \
		$(PARSING_DIR)main.c \
		$(PARSING_DIR)parsing.c \
		$(PARSING_DIR)parsing_utils.c \
		$(PARSING_DIR)ft_find_player.c \
		$(GNL_DIR)get_next_line.c \
        $(GNL_DIR)get_next_line_utils.c \

# Include paths
INCLUDES = -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(PARSING_DIR) -I$(GNL_DIR)

# Objets
OBJS = $(SRCS:.c=.o)

# Bibliothèques
LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re