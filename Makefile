# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/06 17:01:42 by jmeier            #+#    #+#              #
#    Updated: 2018/01/06 17:25:14 by jmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jmeier.filler

FUNC = 

C_LOC = src/
C_NAM = $(addsuffix .c, $(FUNC))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

O_LOC = obj/
O_NAM = $(addsuffix .o, $(FUNC))
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

LIB_LOC = libft/
LIB_NAM = libft.a

H_LOC = -I inc/

all: $(NAME)

lib:
	@make -C $(LIB_LOC)

$(NAME): $(O_SRC)
	@echo Building $@...
	@$(MAKE) lib
	@echo Making libft...
	@echo Making $(NAME)
	@gcc $(O_SRC) -L $(LIB_LOC) -o $(NAME)
	@echo Perfect.

$(O_LOC)%.o: $(C_LOC)%.c
	@gcc -Wall -Werror -Wextra $(H_LOC) -o $@ -c $<

clean:
	@echo Cleaning .o files...
	@/bin/rm -f $(O_SRC) libft.h.gch
	@echo .o files removed.

fclean: clean
	@echo Cleaning $(NAME) ...
	@/bin/rm -f $(NAME)
	@echo $(NAME) removed

re: fclean all

.PHONY: all clean fclean re
