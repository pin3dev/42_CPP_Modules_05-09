# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 14:51:26 by pin3dev           #+#    #+#              #
#    Updated: 2024/03/06 13:30:40 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Base.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = Base.hpp A.hpp B.hpp C.hpp

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