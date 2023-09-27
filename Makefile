# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 19:34:20 by igenial           #+#    #+#              #
#    Updated: 2023/09/27 14:07:02 by igenial          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=
MANDATORY		=
BONUS			=
HEADER			=
LIBFT			=
MANDATORY_FILES	=
BONUS_FILES		=
CC				=
CFLAGS			=
VALGRIND		=	algrind --leak-check=full --show-leak-kinds=all --track-fds=yes
GDB				=	gdb --tui --args

all: $(NAME)

$(NAME): $(MANDATORY_FILES)	$(LBFT)
	$(CC) $(CFLAGS) $(MANDATORY_FILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -f $(MANDATORY_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: all
	$(VALGRIND) ./$(NAME)

gdb: all
	$(GDB) ./$(NAME)

.PHONY:	all clean fclean re 
