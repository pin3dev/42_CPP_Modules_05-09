# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 15:01:43 by pin3dev           #+#    #+#              #
#    Updated: 2024/03/25 11:44:14 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = RPN.hpp

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