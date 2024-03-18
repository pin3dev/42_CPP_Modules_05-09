# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 14:57:54 by pin3dev           #+#    #+#              #
#    Updated: 2024/03/14 15:19:38 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Span.cpp main.cpp testUtils.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = Span.hpp testUtils.hpp mColors.hpp

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