# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 10:55:33 by emimenza          #+#    #+#              #
#    Updated: 2023/10/23 08:41:07 by emimenza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB			=	ar rcs
DEL			=	rm -f
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
NAME		=	get_next_line.a
SRC			=	get_next_line.c get_next_line_utils.c
SRC_BONUS	=	get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
		$(LIB) $(NAME) $(OBJ)
bonus:$(OBJ) $(OBJ_BONUS)
		$(LIB) $(NAME) $(OBJ) $(OBJ_BONUS)
# $@ : The file name of the target of the rule. If the target is an archive member, then ‘$@’ is the name of the archive file.
# $< : The name of the first prerequisite.
%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(DEL) $(OBJ)

clean_bonus:
	$(DEL) $(OBJ) $(OBJ_BONUS)
	
fclean: clean
	$(DEL) $(NAME) bonus

re:	fclean all