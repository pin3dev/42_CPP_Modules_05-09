# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 14:49:56 by pin3dev           #+#    #+#              #
#    Updated: 2024/03/06 12:08:22 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Serialize.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = Serialize.hpp

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HEADER)
	$(CPP) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re