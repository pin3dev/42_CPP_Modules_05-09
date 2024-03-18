# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 14:58:22 by pin3dev           #+#    #+#              #
#    Updated: 2024/03/14 19:22:32 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutant

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  main.cpp testUnits.cpp #boringMain.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = MutantStack.hpp testUnits.hpp

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