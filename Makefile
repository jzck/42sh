# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wescande <wescande@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/29 21:32:58 by wescande          #+#    #+#              #
#    Updated: 2017/03/03 14:36:32 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	42sh

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
D_FLAGS		=	-g 

DELTA		=	$$(echo "$$(tput cols)-47"|bc)

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)includes/

LIBS		=	-ltermcap

SRC_DIR		=	src/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	=	\
builtin/bt_read_get.c\
builtin/bt_read_parse.c\
builtin/bt_read_term.c\
builtin/builtin_cd.c\
builtin/builtin_echo.c\
builtin/builtin_env.c\
builtin/builtin_exit.c\
builtin/builtin_export.c\
builtin/builtin_hash.c\
builtin/builtin_history.c\
builtin/builtin_read.c\
builtin/builtin_setenv.c\
builtin/builtin_unset.c\
builtin/builtin_unsetenv.c\
builtin/is_builtin.c\
completion/c_binary.c\
completion/c_clear.c\
completion/c_files.c\
completion/c_init.c\
completion/c_matching.c\
completion/c_misc.c\
completion/c_output.c\
completion/c_parser.c\
completion/c_pathsolver.c\
completion/c_printer.c\
completion/c_rematch.c\
completion/c_sizing.c\
completion/c_terminal.c\
completion/completion.c\
exec/ast_free.c\
exec/bad_fd.c\
exec/exec_ampersand.c\
exec/exec_and_if.c\
exec/exec_case.c\
exec/exec_case_branch.c\
exec/exec_command.c\
exec/exec_default.c\
exec/exec_elif.c\
exec/exec_else.c\
exec/exec_for.c\
exec/exec_func.c\
exec/exec_if.c\
exec/exec_less.c\
exec/exec_or_if.c\
exec/exec_pipe.c\
exec/exec_redir.c\
exec/exec_semi.c\
exec/exec_until.c\
exec/exec_var.c\
exec/exec_while.c\
exec/fd_is_valid.c\
exec/ft_exec.c\
exec/ft_findexec.c\
exec/launch_process.c\
exec/process_redirect.c\
exec/process_reset.c\
exec/process_resetfds.c\
exec/process_setexec.c\
exec/process_setgroup.c\
exec/process_setsig.c\
exec/redirect_dgreat.c\
exec/redirect_dless.c\
exec/redirect_great.c\
exec/redirect_greatand.c\
exec/redirect_less.c\
exec/redirect_lessand.c\
exec/set_exitstatus.c\
glob/command_getoutput.c\
glob/dir_glob.c\
glob/esc_print.c\
glob/expand_bquote.c\
glob/expand_brace.c\
glob/expand_esc.c\
glob/expand_var.c\
glob/ft_strsplit_esc.c\
glob/ft_strsplit_spe.c\
glob/glob.c\
glob/is_char_esc.c\
glob/lib_perso/ft_ld_back.c\
glob/lib_perso/ft_ld_clear.c\
glob/lib_perso/ft_ld_del.c\
glob/lib_perso/ft_ld_front.c\
glob/lib_perso/ft_ld_new.c\
glob/lib_perso/ft_ld_order.c\
glob/lib_perso/ft_ld_pushback.c\
glob/lib_perso/ft_ld_pushfront.c\
glob/lib_perso/ft_ld_reverse.c\
glob/lib_perso/ft_ld_size.c\
glob/lib_perso/ft_ld_swap.c\
glob/lib_perso/ft_ld_to_tab.c\
glob/lib_perso/ft_memrealloc.c\
glob/lib_perso/ft_strjoinf.c\
glob/lib_perso/ft_strsubf.c\
glob/lib_perso/ft_tabdel.c\
glob/lib_perso/ft_tablen.c\
glob/match_pattern.c\
hash_table/ft_add_hash.c\
hash_table/hash.c\
hash_table/hash_free.c\
hash_table/hash_str.c\
hash_table/is_hash.c\
history/add_str_in_history.c\
history/history.c\
history/history_parsing.c\
history/history_parsing_toolz.c\
history/history_parsing_toolz_2.c\
history/list_toolz.c\
history/surch_in_history.c\
job-control/builtin_bg.c\
job-control/builtin_fg.c\
job-control/builtin_jobs.c\
job-control/do_job_notification.c\
job-control/job_addprocess.c\
job-control/job_cmp_id.c\
job-control/job_format.c\
job-control/job_format_head.c\
job-control/job_free.c\
job-control/job_getprocess.c\
job-control/job_getrank.c\
job-control/job_is_completed.c\
job-control/job_is_stopped.c\
job-control/job_kill_all.c\
job-control/job_notify_change.c\
job-control/job_notify_new.c\
job-control/job_remove.c\
job-control/job_run.c\
job-control/job_update_id.c\
job-control/job_update_status.c\
job-control/job_wait.c\
job-control/mark_job_as_running.c\
job-control/process_cmp_pid.c\
job-control/process_format.c\
job-control/process_free.c\
job-control/process_mark_status.c\
job-control/put_job_in_background.c\
job-control/put_job_in_foreground.c\
job-control/sigchld_handler.c\
job-control/sigint_handler.c\
job-control/sigtstp_handler.c\
job-control/sigttin_handler.c\
job-control/sigttou_handler.c\
lexer/get_lexer_stack.c\
lexer/get_reserved_words.c\
lexer/get_state_global.c\
lexer/get_state_redir.c\
lexer/insert_newline.c\
lexer/lexer_assignement_word.c\
lexer/lexer_backslash.c\
lexer/lexer_bquote.c\
lexer/lexer_comment.c\
lexer/lexer_curly_brackets.c\
lexer/lexer_default.c\
lexer/lexer_delim.c\
lexer/lexer_dless.c\
lexer/lexer_dquote.c\
lexer/lexer_end.c\
lexer/lexer_great.c\
lexer/lexer_greatand.c\
lexer/lexer_init.c\
lexer/lexer_less.c\
lexer/lexer_lessand.c\
lexer/lexer_lex.c\
lexer/lexer_newline.c\
lexer/lexer_number.c\
lexer/lexer_paren.c\
lexer/lexer_quote.c\
lexer/lexer_sep.c\
lexer/lexer_word.c\
lexer/token_append.c\
lexer/token_cmp_type.c\
lexer/token_free.c\
lexer/token_init.c\
lexer/token_print.c\
line-editing/completion.c\
line-editing/control_c_and_d.c\
line-editing/copy_cut_paste.c\
line-editing/ft_prompt.c\
line-editing/get_key.c\
line-editing/home_end.c\
line-editing/lib_line_editing/tool_line.c\
line-editing/lib_line_editing/tool_line_2.c\
line-editing/lib_line_editing/toolz.c\
line-editing/lib_line_editing/toolz2.c\
line-editing/lib_line_editing/toolz_parseur.c\
line-editing/lib_line_editing/toolz_termcaps.c\
line-editing/move_left_and_right.c\
line-editing/move_to_word.c\
line-editing/move_up_and_down.c\
line-editing/print_and_del.c\
line-editing/queue.c\
line-editing/readline.c\
main/data_exit.c\
main/data_init.c\
main/data_singleton.c\
main/ft_putast.c\
main/main.c\
main/shell_exit.c\
main/shell_get_avdata.c\
main/shell_get_opts.c\
main/shell_init.c\
parser/add_case.c\
parser/add_cmd.c\
parser/add_condition.c\
parser/add_func.c\
parser/add_loop.c\
parser/add_redir.c\
parser/add_sep.c\
parser/add_subshell.c\
parser/aggregate_sym.c\
parser/build_tree.c\
parser/error_syntax.c\
parser/eval_sym.c\
parser/ft_parse.c\
parser/parser_init.c\
parser/pop_stack.c\
parser/produce_sym.c\
parser/push_stack.c\
parser/read_stack.c\
parser/tree_wrapper.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all :
	@make -j $(NAME)

$(NAME):		$(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) $(FLAGS) $(D_FLAGS) \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) \
		$(LIBFT_LIB) $(OBJS) \
		-o $(NAME)
	@printf "\r\e[48;5;15;38;5;25m✅ MAKE $(NAME)\e[0m\e[K\n"

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval COLOR=$(shell echo $$(($(PERCENT)%35+196))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB)))))
	@printf "\r\e[38;5;11m⌛ MAKE %10.10s : %2d%% \e[48;5;%dm%*s\e[0m%*s\e[48;5;255m \e[0m \e[38;5;11m %*s\e[0m\e[K" $(NAME) $(PERCENT) $(COLOR) $(DONE) "" $(TO_DO) "" $(DELTA) "$@"
	@$(CC) $(FLAGS) $(D_FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIBFT_INC)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean:			cleanlib
	@rm -rf $(OBJ_DIR)
	@printf "\r\e[38;5;202m✖ clean $(NAME).\e[0m\e[K\n"

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:			clean fcleanlib
	@rm -f $(NAME)
	@printf "\r\e[38;5;196m❌ fclean $(NAME).\e[0m\e[K\n"

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

.PHONY :		fclean clean re relib cleanlib fcleanlib

-include $(OBJS:.o=.d)
