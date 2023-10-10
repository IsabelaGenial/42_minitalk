NAME            =       libft.a
BONUS           =       libft.a
T_RED		=	'\033[0;31M'
T_REDI		=	'\033[3;31M'
T_MAGENTA	=	'\033[0;35M'
T_MAGENTAI	=	'\033[3;35M'
T_YELLOW	=	'\033[0;33M'
T_YELLOWI	=	'\033[3;33M'
T_BLUE		=	'\033[0;34M'
T_BLUEI		=	'\033[3;34M'
T_RESET		=	'\033[0;31M'
SRCS_MANDATORY	=	ft_isalnum.c	ft_isdigit.c	ft_memset.c	ft_strlen.c	\
			ft_tolower.c	ft_isalpha.c	ft_isprint.c	ft_strchr.c 	\
			ft_strncmp.c	ft_toupper.c	ft_isascii.c	ft_memcpy.c	\
			ft_strlcpy.c 	ft_strrchr.c	ft_strlcat.c	ft_strnstr.c	\
			ft_memcmp.c	ft_memmove.c	ft_bzero.c	ft_memchr.c	\
			ft_atoi.c	ft_strdup.c	ft_calloc.c	ft_putchar_fd.c	\
			ft_putnbr_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_itoa.c	\
			ft_striteri.c	ft_strmapi.c	ft_strtrim.c	ft_substr.c	\
			ft_split.c	ft_strjoin.c	get_next_line.c		ft_printf.c	\
			ft_puthex.c	ft_putptr.c
SRCS_BONUS	=	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	ft_lstnew_bonus.c	\
				ft_lstadd_front_bonus.c	ft_lstlast_bonus.c	ft_lstsize_bonus.c	\
				ft_lstclear_bonus.c	ft_lstiter_bonus.c	ft_lstmap_bonus.c
FLAGS		= 	-g3 -Wall -Wextra -Werror
HEADER		=	libft.h
FILES		=	$(SRCS_MANDATORY:%.c=%.o)
BONUS_FILES	=	$(SRCS_BONUS:%.c=%.o)


all:	$(NAME)

$(NAME): $(FILES)
		@echo "$(T_MAGENTAI)Creating $(NAME)...$(T_RESET)"
		@echo "$(T_MAGENTA)$(NAME) created $(T_RESET)"

%.o: %.c
	cc $(FLAGS) -c $< -o $@
	ar -rcs $(NAME) $@
bonus: $(BONUS_FILES)
	@echo "$(T_YELLOWI)Adding bonus files to $(NAME)...$(T_RESET)"
	@echo "$(T_YELLOW)Bonus files added to $(NAME).$(T_RESET)"

norm:
	@echo "$(T_BLUEI)Running norminette...$(T_RESET)"
	@norminette *.c *.h
	@echo "$(T_BLUE)Everything OK.$(T_RESET)"

clean: 
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
	@echo "$(T_RED)Update completed.$(T_RESET)"

.PHONY:all bonus clean fclean re norme
