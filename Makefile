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
builtin/builtin_read.c\
builtin/builtin_setenv.c\
builtin/builtin_unsetenv.c\
builtin/is_builtin.c\
exec/ast_free.c\
exec/exec_ampersand.c\
exec/exec_and_if.c\
exec/exec_command.c\
exec/exec_or_if.c\
exec/exec_pipe.c\
exec/exec_redir.c\
exec/exec_semi.c\
exec/ft_exec.c\
exec/ft_findexec.c\
exec/launch_process.c\
exec/process_do_redirection.c\
exec/process_redirect.c\
exec/process_reset.c\
exec/process_setexec.c\
exec/process_setgroup.c\
exec/process_setsig.c\
exec/set_exitstatus.c\
glob/dir_glob.c\
glob/expand_brace.c\
glob/expand_esc.c\
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
glob/lib_perso/ft_strjoinf.c\
glob/lib_perso/ft_tabdel.c\
glob/lib_perso/ft_tablen.c\
glob/match_pattern.c\
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
lexer/command_getoutput.c\
lexer/ft_lexer.c\
lexer/ft_post_tokenize.c\
lexer/ft_tokenize.c\
lexer/get_lexer_state.c\
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
lexer/lexer_special.c\
lexer/lexer_var.c\
lexer/lexer_word.c\
lexer/reduce_bquotes.c\
lexer/reduce_parens.c\
lexer/token_append.c\
lexer/token_cmp_type.c\
lexer/token_expand_var.c\
lexer/token_free.c\
lexer/token_init.c\
lexer/token_print.c\
line-editing/builtin_history.c\
line-editing/check_backslash.c\
line-editing/completion.c\
line-editing/control_c_and_d.c\
line-editing/copy_cut_paste.c\
line-editing/ft_split_whitespaces.c\
line-editing/get_touch.c\
line-editing/get_touch_toolz.c\
line-editing/get_touch_toolz_2.c\
line-editing/heredoc.c\
line-editing/history.c\
line-editing/history_parsing.c\
line-editing/history_parsing_toolz.c\
line-editing/history_parsing_toolz_2.c\
line-editing/list_toolz.c\
line-editing/move_to_line.c\
line-editing/print_and_del.c\
line-editing/prompt.c\
line-editing/quotes_gest.c\
line-editing/reader.c\
line-editing/readline.c\
line-editing/surch_in_history.c\
line-editing/tool_line.c\
line-editing/tool_line_2.c\
line-editing/toolz.c\
line-editing/toolz2.c\
line-editing/toolz_parseur.c\
line-editing/toolz_termcaps.c\
main/data_exit.c\
main/data_init.c\
main/data_singleton.c\
main/ft_cleanup.c\
main/ft_putast.c\
main/ft_putast2.c\
main/lib_expansion.c\
main/main.c\
main/shell_exit.c\
main/shell_get_avdata.c\
main/shell_get_opts.c\
main/shell_init.c\
main/sig_handler.c\
parser/ft_parse.c\
parser/parse_dgreat.c\
parser/parse_dless.c\
parser/parse_great.c\
parser/parse_greatand.c\
parser/parse_less.c\
parser/parse_lessand.c\
parser/parse_redir.c\
parser/parse_separator.c\
parser/parse_subshell.c\
parser/parse_word.c

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
	@echo "\r\033[48;5;15;38;5;25m✅ MAKE $(NAME)\033[0m\033[K"

$(LIBFT_LIB):
	@make -j -C $(LIBFT_DIR)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval COLOR=$(shell echo $$(($(PERCENT)%35+196))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB)))))
	@printf "\r\033[38;5;11m⌛ MAKE %10.10s : %2d%% \033[48;5;%dm%*s\033[0m%*s\033[48;5;255m \033[0m \033[38;5;11m %*s\033[0m\033[K" $(NAME) $(PERCENT) $(COLOR) $(DONE) "" $(TO_DO) "" $(DELTA) "$@"
	@$(CC) $(FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)\
		-I $(LIBFT_INC)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

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
