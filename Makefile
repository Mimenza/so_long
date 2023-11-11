# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 10:48:36 by emimenza          #+#    #+#              #
#    Updated: 2023/11/12 00:27:54 by emimenza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Definir colores
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m # No color (reiniciar)

#Comandos
DEL			=	rm -f
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
# MLX		=	-framework OpenGL -framework AppKit
MLX			=	-lXext -lX11 -lm -lbsd

#Nombre ejecutable
NAME		=	so_longer
NAME_EXE	=	so_long.exe

#Ficheros
SRC_FILES	=	game map map1 map2 map3 map4 so_long utils window hooks
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
MINILIBX	=	libs/minilibx-linux
GNL			=	libs/gnl
LIBFT		=	libs/Libft
PRINTF		=	libs/ft_printf

#Librerias
LIBS		=	$(MINILIBX)/libmlx.a $(MLX) $(GNL)/get_next_line.a $(PRINTF)/libftprintf.a $(LIBFT)/libft.a 

# Header Files (dedicated and from libraries):
HEADERS		=	 $(MINILIBX)/mlx.h $(GNL)/get_next_line.h $(PRINTF)/ft_printf.h $(LIBFT)/libft.h $(INC)/so_long.h

#Directorios
SRC_DIR = srcs/
OBJ_DIR = objs/
OBJF = objs
INC = incs

# REGLAS #
all:	minilibx gnl printf libft $(NAME)

#Compilar 
$(NAME):$(OBJ)
		@$(CC) $(OBJ) $(LIBS) -o $(NAME)
		@echo "$(GREEN)SO_LONG HAS BEEN COMPILED!$(NC)"

# Compilar objetos individualmente y crear carpeta objs
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)
	@echo "$(YELLOW)Compiled!$(NC)"


# $@ : The file name of the target of the rule. If the target is an archive member, then ‘$@’ is the name of the archive file.
# $< : The name of the first prerequisite.

#compilar librerias individuales
libft:
	@echo "$(YELLOW)COMPILING LIBFT...$(NC)"
	@$(MAKE) -C ./$(LIBFT)
	@echo "$(GREEN)LIBFT HAS BEEN COMPILED$(NC)"

minilibx:
	@echo "$(YELLOW)COMPILING MINILIBX...$(NC)"
	@$(MAKE) -C ./$(MINILIBX)
	@echo "$(GREEN)MINILIBX HAS BEEN COMPILED$(NC)"

gnl:
	@echo "$(YELLOW)COMPILING GNL...$(NC)"
	@$(MAKE) -C ./$(GNL)
	@echo "$(GREEN)GNL HAS BEEN COMPILED$(NC)"

printf:
	@echo "$(YELLOW)COMPILING FT_PRINTF...$(NC)"
	@$(MAKE) -C ./$(PRINTF)
	@echo "$(GREEN)FT_PRINTF HAS BEEN COMPILED$(NC)"

# Eliminar tmp mlx
fclean_mlx:
	@make fclean -C ./$(MINILIBX)
	@echo "$(RED)MINILIBX FULL CLEANED!$(NC)"

# Eliminar tmp ft_printf
fclean_printf:
	@make fclean -C ./$(PRINTF)
	@echo "$(RED)PRINTF FULL CLEANED!$(NC)"

# Eliminar tmp gnl
fclean_gnl:
	@make fclean -C ./$(GNL)
	@echo "$(RED)GNL FULL CLEANED!$(NC)"

# Eliminar tmp libft
fclean_libft:
	@make fclean -C ./$(LIBFT)
	@echo "$(RED)LIBFT FULL CLEANED!$(NC)"


# Eliminar temporales
clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)OBJS AND DIRECTORY CLEANED!$(NC)"

# Eliminar temporales y ejecutable fclean_mlx
fclean: clean  fclean_gnl fclean_libft fclean_printf
	@$(RM) $(NAME)
	@echo "$(RED)EXECUTABLE CLEANED!$(NC)"

#Compilador
exe:
	@echo "$(GREEN)RUNNING....$(NC)"
	@./$(NAME)

re: fclean all