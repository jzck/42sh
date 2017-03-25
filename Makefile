# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wescande <wescande@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/29 21:32:58 by wescande          #+#    #+#              #
#    Updated: 2017/03/25 20:26:47 by jhalford         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	42sh

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address#-fvisibility=hidden
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
completion/c_pathsolver.c\
completion/c_init.c\
completion/c_printer.c\
completion/c_find_binary.c\
completion/c_find_env.c\
completion/c_clear.c\
completion/c_parser.c\
completion/c_arrow.c\
completion/c_sizing.c\
completion/completion.c\
completion/c_match_glob.c\
completion/c_find_files.c\
completion/c_terminal.c\
completion/c_output.c\
completion/c_misc.c\
completion/c_match.c\
completion/c_match_update.c\
completion/c_find_abspath.c\
history/surch_in_history.c\
history/history_parsing_toolz_2.c\
history/history_parsing_toolz.c\
history/list_toolz.c\
history/add_str_in_history.c\
history/history_parsing.c\
history/history.c\
job_control/pprint_while.c\
job_control/mark_job_as_running.c\
job_control/pprint_case.c\
job_control/job_notify_new.c\
job_control/sigint_handler.c\
job_control/job_update_status.c\
job_control/job_format_head.c\
job_control/job_is_completed.c\
job_control/job_wait.c\
job_control/sigtstp_handler.c\
job_control/job_free.c\
job_control/pprint_for.c\
job_control/pprint_if.c\
job_control/job_hup_all.c\
job_control/put_job_in_foreground.c\
job_control/job_is_stopped.c\
job_control/process_free.c\
job_control/sigttin_handler.c\
job_control/sigttou_handler.c\
job_control/builtin_jobs.c\
job_control/process_cmp_pid.c\
job_control/pprint_subshell.c\
job_control/job_remove.c\
job_control/builtin_bg.c\
job_control/job_run.c\
job_control/has_stopped_job.c\
job_control/pprint_cmd.c\
job_control/job_cmp_id.c\
job_control/pprint_brace.c\
job_control/job_addprocess.c\
job_control/job_update_id.c\
job_control/do_job_notification.c\
job_control/job_getrank.c\
job_control/has_running_job.c\
job_control/process_format.c\
job_control/job_getprocess.c\
job_control/job_notify_change.c\
job_control/job_format.c\
job_control/put_job_in_background.c\
job_control/pprint_until.c\
job_control/pprint_function.c\
job_control/builtin_fg.c\
job_control/sigchld_handler.c\
parser/tree_func_free.c\
parser/parser_destroy.c\
parser/tree_wrapper.c\
parser/pop_stack.c\
parser/add_cmd.c\
parser/parser_init.c\
parser/aggregate_sym.c\
parser/redir_init.c\
parser/do_parser_routine.c\
parser/stack_init.c\
parser/add_number.c\
parser/add_func.c\
parser/add_loop.c\
parser/read_stack.c\
parser/push_stack.c\
parser/add_sep.c\
parser/ft_parse.c\
parser/add_condition.c\
parser/produce_sym.c\
parser/heredoc_parser.c\
parser/add_case.c\
parser/sym_free.c\
parser/add_subshell.c\
parser/build_tree.c\
parser/eval_sym.c\
parser/error_syntax.c\
parser/add_bang.c\
parser/add_redir.c\
main/data_exit.c\
main/ft_putast.c\
main/main.c\
main/shell_reset.c\
main/data_singleton.c\
main/data_init.c\
main/shell_init.c\
line_editing/lib_line_editing/toolz_termcaps.c\
line_editing/lib_line_editing/tool_line_2.c\
line_editing/lib_line_editing/tool_line.c\
line_editing/lib_line_editing/toolz.c\
line_editing/lib_line_editing/toolz_parseur.c\
line_editing/lib_line_editing/ft_nb_line.c\
line_editing/lib_line_editing/toolz2.c\
line_editing/resize.c\
line_editing/control_features.c\
line_editing/print_del_completion/queue.c\
line_editing/print_del_completion/completion.c\
line_editing/print_del_completion/print_and_del.c\
line_editing/get_key.c\
line_editing/ft_prompt.c\
line_editing/readline.c\
line_editing/move_term/move_up_and_down.c\
line_editing/move_term/home_end.c\
line_editing/move_term/move_to_word.c\
line_editing/move_term/move_left_and_right.c\
line_editing/init_line/init_termcaps.c\
line_editing/init_line/init_history.c\
line_editing/init_line/init_line.c\
line_editing/copy_cut_paste/underline_home.c\
line_editing/copy_cut_paste/underline_down.c\
line_editing/copy_cut_paste/underline_end.c\
line_editing/copy_cut_paste/underline_reset.c\
line_editing/copy_cut_paste/underline_function.c\
line_editing/copy_cut_paste/copy_cut_paste.c\
line_editing/copy_cut_paste/underline_right.c\
line_editing/copy_cut_paste/underline_up.c\
line_editing/copy_cut_paste/underline_left.c\
glob/expand_home.c\
glob/expand_bquote.c\
glob/dir_glob.c\
glob/ft_strsplit_esc.c\
glob/expand_var.c\
glob/glob.c\
glob/word_is_assignment.c\
glob/match_pattern.c\
glob/lib_perso/ft_ld_front.c\
glob/lib_perso/ft_ld_new.c\
glob/lib_perso/ft_ld_size.c\
glob/lib_perso/ft_tablen.c\
glob/lib_perso/ft_ld_pushfront.c\
glob/lib_perso/ft_ld_swap.c\
glob/lib_perso/ft_ld_order.c\
glob/lib_perso/ft_strsubf.c\
glob/lib_perso/ft_ld_reverse.c\
glob/lib_perso/ft_ld_to_tab.c\
glob/lib_perso/ft_tabdel.c\
glob/lib_perso/ft_strjoinf.c\
glob/lib_perso/ft_ld_del.c\
glob/lib_perso/ft_ld_back.c\
glob/lib_perso/ft_memrealloc.c\
glob/lib_perso/ft_ld_copy.c\
glob/lib_perso/ft_ld_pushback.c\
glob/lib_perso/ft_ld_clear.c\
glob/expand_brace.c\
glob/tab_esc_copy.c\
glob/ft_strsplit_spe.c\
glob/esc_print.c\
glob/expand_esc.c\
glob/is_char_esc.c\
glob/command_getoutput.c\
glob/gen_tab_esc.c\
lexer/lexer_delim.c\
lexer/lexer_paren.c\
lexer/get_state_redir.c\
lexer/lexer_quote.c\
lexer/lexer_dquote.c\
lexer/token_free.c\
lexer/token_cmp_type.c\
lexer/lexer_sep.c\
lexer/lexer_heredoc.c\
lexer/token_init.c\
lexer/lexer_less.c\
lexer/insert_newline.c\
lexer/get_lexer_stack2.c\
lexer/lexer_init.c\
lexer/keep_last_type.c\
lexer/isrw_delim.c\
lexer/lexer_lex.c\
lexer/lexer_destroy.c\
lexer/lexer_word.c\
lexer/lexer_newline.c\
lexer/get_lexer_stack.c\
lexer/lexer_great.c\
lexer/lexer_curly_braces.c\
lexer/lexer_end.c\
lexer/get_reserved_words.c\
lexer/do_lexer_routine.c\
lexer/token_append.c\
lexer/get_state_global.c\
lexer/lexer_bquote.c\
lexer/lexer_default.c\
lexer/token_print.c\
lexer/lexer_backslash.c\
lexer/lexer_number.c\
builtin/builtin_func.c\
builtin/builtin_export.c\
builtin/builtin_unsetenv.c\
builtin/builtin_setenv.c\
builtin/builtin_unset.c\
builtin/builtin_math.c\
builtin/bt_read_term.c\
builtin/builtin_echo.c\
builtin/builtin_hash.c\
builtin/bt_env_opt.c\
builtin/builtin_exit.c\
builtin/builtin_cd.c\
builtin/builtin_read.c\
builtin/is_builtin.c\
builtin/bt_read_get.c\
builtin/builtin_history.c\
builtin/builtin_env.c\
exec/pset_brace.c\
exec/pset_if.c\
exec/pfree_func.c\
exec/plaunch_subshell.c\
exec/pset_case.c\
exec/exec_ampersand.c\
exec/exec_and_if.c\
exec/exec_var.c\
exec/exec_case_branch.c\
exec/redirect_greatand.c\
exec/redir_copy.c\
exec/redir_free.c\
exec/token_to_argv.c\
exec/exec_pipe.c\
exec/pfree_cond.c\
exec/pset_for.c\
exec/pset_until.c\
exec/exec_func.c\
exec/exec_or_if.c\
exec/node_copy.c\
exec/pfree_list.c\
exec/redirect_dless.c\
exec/exec_bang.c\
exec/redirect_dgreat.c\
exec/mark_process_status.c\
exec/plaunch_for.c\
exec/is_function.c\
exec/pset_while.c\
exec/exec_else.c\
exec/ast_free.c\
exec/exec_semi.c\
exec/plaunch_while.c\
exec/bad_fd.c\
exec/exec_leaf.c\
exec/plaunch_if.c\
exec/plaunch_case.c\
exec/process_redirect.c\
exec/process_setgroup.c\
exec/ft_exec.c\
exec/set_exitstatus.c\
exec/plaunch_brace.c\
exec/plaunch_empty.c\
exec/redirect_great.c\
exec/process_set.c\
exec/exec_reset.c\
exec/plaunch_until.c\
exec/pset_cmd.c\
exec/redirect_lessand.c\
exec/ft_findexec.c\
exec/redirect_less.c\
exec/pset_subshell.c\
exec/fd_is_valid.c\
exec/exec_elif.c\
exec/plaunch_builtin.c\
exec/pfree_subshell.c\
exec/plaunch_file.c\
exec/process_setsig.c\
exec/plaunch_function.c\
exec/process_launch.c\
exec/pfree_cmd.c\
hash_table/ft_add_hash.c\
hash_table/is_hash.c\
hash_table/hash.c\
hash_table/hash_free.c\
hash_table/hash_str.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all :
	@make -C $(LIBFT_DIR)
	@make -j $(NAME)

$(NAME):		$(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) \
		-I $(INC_DIR) \
		-I $(LIBFT_INC) \
		$(LIBS) \
		$(LIBFT_LIB) \
		$(FLAGS) $(D_FLAGS)
	@strip -x $@
	@printf "\r\033[48;5;15;38;5;25m✅ MAKE $(NAME)\033[0m\033[K\n"

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
	@printf "\r\033[38;5;11m⌛ MAKE %10.10s : %2d%% \033[48;5;%dm%*s\033[0m%*s\033[48;5;255m \033[0m \033[38;5;11m %*.*s\033[0m\033[K" $(NAME) $(PERCENT) $(COLOR) $(DONE) "" $(TO_DO) "" $(DELTA) $(DELTA) "$@"
	@$(CC) $(FLAGS) $(D_FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIBFT_INC)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean:			cleanlib
	@rm -rf $(OBJ_DIR)
	@printf "\r\033[38;5;202m✖ clean $(NAME).\033[0m\033[K\n"

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:			clean fcleanlib
	@rm -f $(NAME)
	@printf "\r\033[38;5;196m❌ fclean $(NAME).\033[0m\033[K\n"

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

.PHONY :		fclean clean re relib cleanlib fcleanlib

-include $(OBJS:.o=.d)
