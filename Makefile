# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 10:48:36 by emimenza          #+#    #+#              #
#    Updated: 2023/12/15 08:26:26 by emimenza         ###   ########.fr        #
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
MLX			=	-framework OpenGL -framework AppKit
#MLX			=	-lXext -lX11 -lm -lbsd
# -g3 -fsanitize=address

#Nombre ejecutable
NAME		=	so_long
NAME_BONUS	=	so_long_bonus

#Ficheros
SRC_FILES	=	00_main 01_game 02_map 02_map1 02_map2 02_map3 02_map5 03_window 04_print_map 05_hooks 06_move 08_error 09_utils 10_free
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

SRC_FILES_BONUS	= 00_main 01_game 02_map 02_map1 02_map2 02_map3 02_map5 03_window 04_print_map 05_hooks 06_move 08_error 09_utils 10_free 
SRC_BONUS	=	$(addprefix $(SRC_DIR_BONUS), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJ_BONUS	=	$(addprefix $(OBJ_DIR_BONUS), $(addsuffix .o, $(SRC_FILES_BONUS)))

MINILIBX	=	libs/minilibx
GNL			=	libs/gnl
LIBFT		=	libs/Libft
PRINTF		=	libs/ft_printf

#Librerias 
LIBS		= $(MINILIBX)/libmlx.a $(MLX) $(GNL)/get_next_line.a $(PRINTF)/libftprintf.a $(LIBFT)/libft.a 

#Directorios
SRC_DIR = srcs/
OBJ_DIR = objs/

SRC_DIR_BONUS = srcs_bonus/
OBJ_DIR_BONUS = objs_bonus/

# REGLAS # 
all:	minilibx gnl printf libft $(NAME)
bonus:	minilibx gnl printf libft $(NAME_BONUS)

#Compilar 
$(NAME):$(OBJ)
		@$(CC) $(OBJ) $(LIBS) -o $(NAME)
		@echo "$(GREEN)SO_LONG HAS BEEN COMPILED!$(NC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(YELLOW)Compiled!$(NC)"

#Compilar bonus
$(NAME_BONUS):$(OBJ_BONUS)
		@$(CC) $(OBJ_BONUS) $(LIBS) -o $(NAME_BONUS)
		@echo "$(GREEN)SO_LONG HAS BEEN COMPILED!$(NC)"

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< 
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

# Eliminar temporales
clean_bonus:
	@$(RM) -r $(OBJ_DIR_BONUS)
	@echo "$(RED)OBJS AND DIRECTORY CLEANED!$(NC)"

# Eliminar temporales y ejecutable fclean_mlx
fclean: clean  fclean_gnl fclean_libft fclean_printf
	@$(RM) $(NAME)
	@echo "$(RED)EXECUTABLE CLEANED!$(NC)"

# Eliminar temporales y ejecutable fclean_mlx
fclean_bonus: clean clean_bonus fclean_gnl fclean_libft fclean_printf
	@$(RM) $(NAME_BONUS)
	@echo "$(RED)EXECUTABLE CLEANED!$(NC)"

re: fclean all