# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 19:34:20 by igenial           #+#    #+#              #
#    Updated: 2023/09/28 16:15:21 by igenial          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_CLIENT		=	client
NAME_SERVER		= 	server
S_MANDATORY		=	server.c
S_FILES			=	$(S_MANDATORY:%.c=%.o)
C_MANDATORY		=	client.c
C_FILES			=	$(C_MANDATORY:%.c=%.o)
S_BONUS			=	server_bonus.c
c_BONUS			=	client_bonus.c
LIBFT			= 	libft.a
HEADER			= 	mini_talk.h
HEADER_LIB		=	libfstonk/libft.h
HEADER_BONUS	=	mini_talk_bonus.h
BONUS_FILES		=
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
VALGRIND		=	algrind --leak-check=full --show-leak-kinds=all --track-fds=yes
GDB				=	gdb --tui --args

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(S_FILES)	$(LBFT)
	$(CC) $(CFLAGS) $(S_FILES) $(LIBFT) -o $(NAME_SERVER)

$(S_FILES): $(S_MANDATORY)
	$(CC) $(CFLAGS) -I $(HEADER_LIB) -c $< -o $@

$(NAME_CLIENT): $(C_FILES) $(LBFT)
	$(CC) $(CFLAGS) $(C_FILES) $(LIBFT) -o $(NAME_CLIENT)

$(C_FILES): $(C_MANDATORY)
	$(CC) $(CFLAGS)  -c $< -o $@

bonus:
	@make C_FILES="$(C_BONUS)" S_FILES="$(S_BONUS)"

libft:
	make  -C libfstonk

clean:
	rm -f $(S_FILES) $(C_FILES) 

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) 

re: fclean all

valgrind: all
	$(VALGRIND) ./$(NAME_CLIENT)

gdb: all
	$(GDB) ./$(NAME_CLIENT)

.PHONY:	all clean fclean re 
