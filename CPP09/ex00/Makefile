# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 15:01:03 by pin3dev           #+#    #+#              #
#    Updated: 2024/03/20 16:08:45 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  main.cpp BitcoinExchange.cpp BitcoinDataBase.cpp Checker.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = BitcoinExchange.hpp BitcoinDataBase.hpp Checker.hpp

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