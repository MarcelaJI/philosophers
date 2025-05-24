# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 09:35:49 by ingjimen          #+#    #+#              #
#    Updated: 2025/05/22 08:17:18 by ingjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g

SRC	= src/main.c \
		src/parse_data.c \
		src/parse_data_utils.c \
		src/init_sim.c \
		src/philo_routine.c \
		src/philo_routine_utils.c \
		src/threads.c \
		src/monitor.c \
		src/utils.c \
		src/clean.c \
		src/error.c 

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
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing .o files$(NC)"
	rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing executable$(NC)"
	rm -f $(NAME)

re: fclean all