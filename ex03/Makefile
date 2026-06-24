# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/23 10:46:20 by marvin            #+#    #+#              #
#    Updated: 2026/06/23 10:46:20 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= a.out

SRC			= main.cpp Bureaucrat.cpp AForm.cpp \
ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp \
Intern.cpp

OBJ			= $(SRC:.cpp=.o)

HEADER		= -I ./
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
