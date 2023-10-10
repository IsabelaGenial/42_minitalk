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
HEADER			= 	mini_talk.h
LIB				=	libfstonk/libft.a
HEADER_BONUS	=	mini_talk_bonus.h
C_BONUS	 		= 	client_bonus.c
S_BONUS			=	server_bonus.c
CC				=	cc
CFLAGS			=	-g3 -Wall -Wextra -Werror
VALGRIND		=	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes
GDB				=	gdb --tui --args

all: libft
	make $(NAME_SERVER)
	make $(NAME_CLIENT)

$(NAME_SERVER): $(S_FILES)
	$(CC) $(CFLAGS) -I. $(S_FILES) $(LIB) -o $(NAME_SERVER)

$(S_FILES): $(S_MANDATORY)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_CLIENT): $(C_FILES)
	$(CC) $(CFLAGS) $(C_FILES) $(LIB) -o $(NAME_CLIENT)

$(C_FILES): $(C_MANDATORY)
	$(CC) $(CFLAGS)  -c $< -o $@

bonus:
	@make fclean
	@make C_FILES="$(C_BONUS)" S_FILES="$(S_BONUS)"

libft:
	make -C libfstonk

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
