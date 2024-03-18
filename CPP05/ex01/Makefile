# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 17:42:20 by pin3dev           #+#    #+#              #
#    Updated: 2024/03/13 17:14:32 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g

SRC = Bureaucrat.cpp Form.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = Bureaucrat.hpp Form.hpp

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