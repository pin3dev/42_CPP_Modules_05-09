# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 15:02:32 by pin3dev           #+#    #+#              #
#    Updated: 2024/05/29 00:52:34 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  main.cpp PmergeMe.cpp Logger.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = PmergeMe.hpp

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