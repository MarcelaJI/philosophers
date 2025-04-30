# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 11:41:09 by ingjimen          #+#    #+#              #
#    Updated: 2025/04/30 11:46:48 by ingjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g

SRC	= main.c

OBJS	= $(SRC:.c=.o)

GREEN = \033[0;32m
RED = \033[1;31m
BLUE_UNDER = \033[1;34m
YELLOW = \033[0;33m
CYAN = \033[1;36m
MAGENTA = \033[0;35m
WHITE = \033[1;37m
WHITE_RED_BG = \033[0;41;37m
YELLOW_UNDER = \033[1;4;33m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling $(NAME)$(NC)"
	$(CC) $(CFLAGS) $(OBJS) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing .o files in all directories$(NC)"
	rm -f $(OBJS)
	@$(MAKE) clean -C

fclean: clean
	@echo "$(RED)Removing .a files and executables$(NC)"
	rm -f $(NAME)
	@$(MAKE) fclean -C

re: fclean all