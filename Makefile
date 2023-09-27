# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 19:34:20 by igenial           #+#    #+#              #
#    Updated: 2023/09/27 18:39:18 by igenial          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_CLIENT		=	client
NAME_SERVER		= 	server
MANDATORY		=	client.c
BONUS			=
HEADER			=
LIBFT			=
MANDATORY_FILES	=
BONUS_FILES		=
CC				=
CFLAGS			=
VALGRIND		=	algrind --leak-check=full --show-leak-kinds=all --track-fds=yes
GDB				=	gdb --tui --args

all: $(NAME_CLIENT)

$(NAME_CLIENT): $(MANDATORY_FILES)	$(LBFT)
	$(CC) $(CFLAGS) $(MANDATORY_FILES) $(LIBFT) -o $(NAME_CLIENT)

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -f $(MANDATORY_FILES)

fclean: clean
	rm -f $(NAME_CLIENT)

re: fclean all

valgrind: all
	$(VALGRIND) ./$(NAME_CLIENT)

gdb: all
	$(GDB) ./$(NAME_CLIENT)

.PHONY:	all clean fclean re 
