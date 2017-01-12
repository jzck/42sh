<<<<<<< HEAD
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
D_FLAGS	=	-g

MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): libft/libft.a $(DF_OBJ)
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

$(D_OBJ)/%.o: $(D_SRC)/line-editing/%.c includes/ft_readline.h
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

$(D_OBJ)/%.o: $(D_SRC)/job-control/%.c includes/job_control.h
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

libft/libft.a: libft/src/*/*.c
	@echo "libft/libft.a"
	@$(MAKE) -C libft 2>/dev/null

libft:
	@echo "libft"
	@$(MAKE) -C libft 2>/dev/null

clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) fclean -C libft/ 2>/dev/null

re: fclean all
=======
#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/29 21:32:58 by wescande          #+#    #+#             *#
#*   Updated: 2016/09/27 20:14:55 by wescande         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME		=	42sh

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
D_FLAGS		=	-g

LEN_NAME	=	`printf "%s" $(NAME) |wc -c`
DELTA		=	$$(echo "$$(tput cols)-24-$(LEN_NAME)"|bc)

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)includes/

LIBS		=	-ltermcap

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	=	\
builtin/builtin.c\
builtin/builtin_cd.c\
builtin/builtin_echo.c\
builtin/builtin_env.c\
builtin/builtin_exit.c\
builtin/builtin_setenv.c\
builtin/builtin_unsetenv.c\
exec/ast_free.c\
exec/exec_and_if.c\
exec/exec_command.c\
exec/exec_dgreat.c\
exec/exec_great.c\
exec/exec_less.c\
exec/exec_or_if.c\
exec/exec_pipe.c\
exec/exec_semi.c\
exec/fd_redirect.c\
exec/ft_cmd.c\
exec/ft_exec.c\
exec/ft_findexec.c\
exec/set_exitstatus.c\
glob/expand_brace.c\
glob/glob.c\
glob/glob_print.c\
glob/ld/ft_ld_back.c\
glob/ld/ft_ld_clear.c\
glob/ld/ft_ld_del.c\
glob/ld/ft_ld_front.c\
glob/ld/ft_ld_new.c\
glob/ld/ft_ld_pushback.c\
glob/ld/ft_ld_pushfront.c\
glob/ld/ft_ld_reverse.c\
glob/ld/ft_ld_size.c\
glob/ld/ft_ld_swap.c\
glob/ld/ft_ld_to_tab.c\
lexer/ft_tokenize.c\
lexer/lexer_backslash.c\
lexer/lexer_default.c\
lexer/lexer_delim.c\
lexer/lexer_dquote.c\
lexer/lexer_great.c\
lexer/lexer_greatand.c\
lexer/lexer_less.c\
lexer/lexer_lessand.c\
lexer/lexer_number.c\
lexer/lexer_quote.c\
lexer/lexer_sep.c\
lexer/lexer_word.c\
lexer/token_append.c\
lexer/token_cmp_type.c\
lexer/token_free.c\
lexer/token_init.c\
lexer/token_print.c\
line-editing/curs_ask.c\
line-editing/curs_clear.c\
line-editing/curs_goto.c\
line-editing/curs_move.c\
line-editing/curs_setup.c\
line-editing/curs_single.c\
line-editing/curs_term_setup.c\
line-editing/curs_write.c\
line-editing/ft_interactive_sh.c\
line-editing/ft_readline.c\
line-editing/rl_bitset.c\
line-editing/rl_clear_function.c\
line-editing/rl_clipboard_function.c\
line-editing/rl_clipboard_utility.c\
line-editing/rl_comp_function.c\
line-editing/rl_default_function.c\
line-editing/rl_display.c\
line-editing/rl_dynamic_buffer.c\
line-editing/rl_long_move_function.c\
line-editing/rl_merge_line.c\
line-editing/rl_page_move_function.c\
line-editing/rl_prompt.c\
line-editing/rl_quoting_function.c\
line-editing/rl_remove_function.c\
line-editing/rl_setup.c\
line-editing/rl_short_move_function.c\
line-editing/rl_stack_line.c\
line-editing/rl_state_function.c\
line-editing/rl_word_move_function.c\
line-editing/rl_word_utility.c\
main/data_exit.c\
main/data_init.c\
main/ft_cleanup.c\
main/ft_putast.c\
main/ft_putast2.c\
main/lib_expansion.c\
main/main.c\
main/sig_handler.c\
parser/ft_parse.c\
parser/parse_dgreat.c\
parser/parse_dless.c\
parser/parse_great.c\
parser/parse_greatand.c\
parser/parse_less.c\
parser/parse_lessand.c\
parser/parse_separator.c\
parser/parse_word.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all :			$(NAME)

$(NAME):		$(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) $(FLAGS) $(D_FLAGS) \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) \
		$(LIBFT_LIB) $(OBJS) \
		-o $(NAME)
	@echo "\r\033[48;5;15;38;5;25m✅ MAKE $(NAME)\033[0m\033[K"

$(LIBFT_LIB):
	@make -j -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIBFT_INC)
	@printf "\r\033[38;5;11m⌛ MAKE %s     plz wait :  %*s\033[0m\033[K" $(NAME) $(DELTA) "$@"

clean:			cleanlib
	@rm -rf $(OBJ_DIR)
	@echo "\r\033[38;5;202m✖ clean $(NAME).\033[0m\033[K"

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:			clean fcleanlib
	@rm -f $(NAME)
	@echo "\r\033[38;5;196m❌ fclean $(NAME).\033[0m\033[K"

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

.PHONY :		fclean clean re relib cleanlib fcleanlib

-include $(OBJS:.o=.d)
>>>>>>> premier commit. working. . .
