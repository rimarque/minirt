# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rita <rita@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 14:39:30 by rimarque          #+#    #+#              #
#    Updated: 2023/12/27 22:09:09 by rita             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 

NAME = mathvec.a

CC = cc

CFLAGS  = -Wall -Wextra -Werror

RM = rm -rf

OBJ = $(SRC:.c=.o)

HRD =

all: $(NAME)

$(NAME): $(OBJ)
	echo "ups"
	@ar rcs $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re bonusre
