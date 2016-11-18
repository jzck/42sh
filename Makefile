NAME	=	minishell
CC		=	gcc
TAGFILE	=	.tags

D_SRC	=	src
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

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): $(DF_OBJ) libft
	$(CC) $(O_INC) $(O_SER) $(O_LIB) $(W_FLAGS) $(DF_OBJ) -o $@ $(D_FLAGS)

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

$(D_OBJ)/%.o: $(D_SRC)/lexer/%.c includes/lexer.h
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

$(D_OBJ)/%.o: $(D_SRC)/parser/%.c includes/parser.h
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

$(D_OBJ)/%.o: $(D_SRC)/exec/%.c includes/exec.h
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

libft:
	@$(MAKE) -C libft/ 2>/dev/null

clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	@$(MAKE) re -C libft/ 2>/dev/null
