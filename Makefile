# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 15:13:13 by bahbibe           #+#    #+#              #
#    Updated: 2023/01/02 20:59:48 by bahbibe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Off		=\033[0m
Black	=\033[0;30m
Red		=\033[0;31m
Green	=\033[0;32m
Yellow	=\033[0;33m
Blue	=\033[0;34m
Purple	=\033[0;35m
Cyan	=\033[0;36m
White	=\033[0;37m

CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
NAME	=	minitalk
SRV_NAME	=	server 
CLT_NAME	=	client 
SRV_SRCS	=	src/server.c 
CLT_SRCS	=	src/client.c 
SRV_BONUS_NAME	=	server_bonus
CLT_BONUS_NAME	=	client_bonus 
SRV_BONUS_SRCS	=	src/server_bonus.c 
CLT_BONUS_SRCS	=	src/client_bonus.c 
LIBS		=	libft
INCLUDES	=	$(LIBS:%=includes/$*/%.a)


all: $(LIBS) $(NAME)
	@:
bonus:$(LIBS) $(SRV_BONUS_NAME) $(CLT_BONUS_NAME)
$(NAME): $(SRV_NAME) $(CLT_NAME)
$(SRV_NAME): $(SRV_SRCS)
	@$(CC) -I includes $(FLAGS) $(SRV_SRCS) $(INCLUDES) -o $(SRV_NAME)
	@printf '\r$ $(Green) Server Compiled ✅ $(Off)\n'
$(CLT_NAME): $(CLT_SRCS)
	@$(CC) -I includes $(FLAGS) $(CLT_SRCS) $(INCLUDES) -o $(CLT_NAME)
	@printf '\r$ $(Green) Client Compiled ✅ $(Off)\n'
$(SRV_BONUS_NAME): $(SRV_BONUS_SRCS)
	@$(CC) -I includes $(FLAGS) $(SRV_BONUS_SRCS) $(INCLUDES) -o $(SRV_BONUS_NAME)
	@printf '\r$ $(Green) Server_bonus Compiled ✅ $(Off)\n'
$(CLT_BONUS_NAME): $(CLT_BONUS_SRCS)
	@$(CC) -I includes $(FLAGS) $(CLT_BONUS_SRCS) $(INCLUDES) -o $(CLT_BONUS_NAME)
	@printf '\r$ $(Green) Client_bonus Compiled ✅ $(Off)\n'
libs: $(LIBS)
$(LIBS):
	@make -C includes/$@
	@cp includes/$@/$@.a includes
clean:
	@make -C includes/libft clean
	@printf '\r$ $(Cyan) Cleaned ✅ $(Off)\n'
fclean: clean
	@make -C includes/libft fclean
	@rm -rf $(SRV_NAME)
	@rm -rf $(CLT_NAME)
	@rm -rf $(SRV_BONUS_NAME)
	@rm -rf $(CLT_BONUS_NAME)
	@rm -rf $(INCLUDES)
re: fclean all
.PHONY: all