GCC			=	@gcc -Wall -Werror -Wextra
LIB 		=
NAME 		=	philo_bonus
SRC 		= 	$(addprefix srcs/, main.c)
HEADER 		=	$(addprefix includes/, philo.h)
OBJ 		=	$(SRC:.c=.o)
COM_STRING 	=	"Compiling"
COM_COLOR   =	\033[0;34
NO_COLOR    =	\033[m
OBJ_COLOR   =	\033[0;36m


all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) -o $(NAME) $(LIB) $(OBJ)
	@printf "%b" "\033[0;32m $(NAME) is done !$(NO_COLOR)\n"


bonus: $(OBJBONUS)
	$(GCC) -o $(NAME) $(LIB) $(OBJBONUS)
	@printf "%b" "\033[0;32m $(NAME) is done !$(NO_COLOR)\n"

%.o: %.c $(HEADER) $(SRC)
	@printf "%b" "\033c";
	@printf "%b" "$(COM_STRING) $(OBJ_COLOR)$(@)$(NO_COLOR)\n";
	$(GCC) -o $@ -c $< -I $(HEADER)

clean:
	@rm -f $(OBJ)
	@printf "%b" "\033[0;32m clean $(NAME)$(NO_COLOR)\n"

fclean:
	@rm -f $(NAME) $(OBJ)
	@printf "%b" "\033[0;32m fclean $(NAME)$(NO_COLOR)\n"

re: fclean all