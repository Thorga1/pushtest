# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tordner <tordner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:28:00 by tordner           #+#    #+#              #
#    Updated: 2024/07/26 15:20:38 by tordner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	

OBJ		=	$(SRC:.c=.o)

NAME	=	push_swap

HEADERS	=	-I includes

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			cc $(HEADERS) $(SRC) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
