NAME = libftprintf.a

SRC = ft_conv_hexa.c ft_printf.c ft_putadd.c ft_putchar.c ft_putnbr_unsigned.c \
	  ft_putnbr.c ft_putstr.c ft_strlen.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
EXEC = main

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Création de la librairie $(NAME)..."
	ar rcs $(NAME) $(OBJ)

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
