# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:06:30 by cyferrei          #+#    #+#              #
#    Updated: 2024/11/15 15:34:27 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = littleRpg
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
SRC = AMateria.cpp Ice.cpp ICharacter.cpp Character.cpp Cure.cpp IMateriaSource.cpp MateriaSource.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

BOLD    = \e[1m
FADE    = \e[2m
ITA     = \e[3m
BLINK   = \e[5m
GREEN   = \e[38;5;76m
RED     = \e[38;5;196m
YELLOW  = \e[38;5;227m
ORANGE  = \e[38;5;208m
PURPLE  = \e[38;5;201m
LBLUE   = \e[38;5;45m
BLUE    = \e[38;5;27m
INDI    = \e[38;5;91m
SPINK   = \e[38;5;225m
PEACH   = \e[38;5;223m
GREY    = \e[38;5;254m
RESET   = \e[00m

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(BOLD)Linking...$(RESET)"
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable '$(NAME)' created successfully!$(RESET)"

clean:
	@echo "$(BOLD)Cleaning object files...$(RESET)"
	$(RM) $(OBJ)
	@echo "$(GREEN)Object files cleaned successfully!$(RESET)"

fclean: clean
	@echo "$(BOLD)Cleaning object files...$(RESET)"
	$(RM) $(NAME)
	@echo "$(GREEN)Object files cleaned successfully!$(RESET)"

re: fclean all

.PHONY: all clean fclean re