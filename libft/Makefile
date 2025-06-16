NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
      ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
      ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
      ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
      ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
      ft_strtrim.c ft_split.c ft_itoa.c ft_striteri.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
      ft_strrchr.c ft_strmapi.c 

SRCBONUS = ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstiter_bonus.c \
ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstclear_bonus.c \
ft_lstdelone_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
EXEC = main

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Création de la librairie $(NAME)..."
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJBONUS)
	@echo "Création de la librairie bonus $(NAME)..."
	ar rcs $(NAME) $(OBJ) $(OBJBONUS)

%.o: %.c
	@echo "Compilation de $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Suppression des fichiers objets..."
	$(RM) $(OBJ) $(OBJBONUS)
	@echo "Nettoyage terminé."

fclean: clean
	@echo "Suppression de la librairie $(NAME) et de l'exécutable $(EXEC)..."
	$(RM) $(NAME) $(EXEC)
	@echo "Tout est propre."

re: fclean all

$(EXEC): $(NAME) main.c
	@echo "Compilation de l'exécutable $(EXEC)..."
	$(CC) $(CFLAGS) main.c -L. -lft -o $(EXEC)
	@echo "Exécutable $(EXEC) créé avec succès."
