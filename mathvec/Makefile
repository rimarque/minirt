# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 14:39:30 by rimarque          #+#    #+#              #
#    Updated: 2024/01/16 11:37:03 by rimarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = len_vec2.c len_vec3.c math_vec2.c math_vec3.c prod_vec2.c prod_vec3.c rotate_vec3.c print_vec3.c

NAME = mathvec.a

CC = cc

CFLAGS  = -Wall -Wextra -Werror

RM = rm -rf

OBJ = $(SRC:.c=.o)

HRD = includes/mathvec.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re bonusre
