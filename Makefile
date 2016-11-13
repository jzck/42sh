NAME	=	minishell
CC		=	gcc
TAGFILE	=	.tags

D_SRC	=	src
# F_SRC	:=	$(shell ls -1 $(D_SRC) | grep "\.c$$")
# F_SRC	:=	$(addprefix $(D_SRC)/, $(F_SRC))
F_SRC   :=  $(shell find $(D_SRC) -type f -regex ".*\.c$$")

D_OBJ	=	obj
F_OBJ	=	$(notdir $(F_SRC:.c=.o))
DF_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

D_INC	=	includes libft/includes
F_INC   :=  $(shell find $(D_INC) -type f -regex ".*\.h$$")
O_INC	=	$(addprefix -I, $(D_INC))

D_SER	=	libft/
O_SER	=	$(addprefix -L, $(D_SER))

D_LIB	=	ft ncurses
O_LIB	=	$(addprefix -l, $(D_LIB))

W_FLAGS	=	-Wall -Wextra -Werror
D_FLAGS	=

MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

.PHONY: all clean fclean re tags test libft

all: $(NAME)

$(D_OBJ)/%.o: $(D_SRC)/main/%.c includes/minishell.h
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

$(D_OBJ)/%.o: $(D_SRC)/builtin/%.c includes/minishell.h
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

$(D_OBJ)/%.o: $(D_SRC)/minishell-exec/%.c includes/minishell.h
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

$(D_OBJ)/%.o: $(D_SRC)/line-editing/%.c includes/line_editing.h
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

$(D_OBJ)/%.o: $(D_SRC)/lexer-parser/%.c includes/lexer_parser.h
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

$(D_OBJ)/%.o: $(D_SRC)/exec/%.c includes/exec.h
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

libft/libft.a:
	@$(MAKE) -C libft/ 2>/dev/null

$(NAME): $(DF_OBJ) libft/libft.a
	$(CC) $(O_INC) $(O_SER) $(O_LIB) $(W_FLAGS) $(DF_OBJ) -o $@ $(D_FLAGS)

clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
