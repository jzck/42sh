/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:02:25 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/10 13:22:13 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# include "libft.h"
# include "ft_curs.h"

/*
 * Input-Key Mapping !!! LINUX Or MACOSX !!!
*/

//# define LINUX
# define MACOSX
# include "ft_input.h"

/*
 * Default offset for dynamic allocation
*/

# define RL_OFFSET 1024

/*
 * Readline possible prompt
*/

# define RL_PROMPT_DEFAULT "$> "
# define RL_PROMPT_ESC "> "
# define RL_PROMPT_QUOTE "quote> "
# define RL_PROMPT_DQUOTE "double quote> "

/*
 * Bitset manipulation : X is the bitset and Y is the bit to manipulate
 * IS : Is Y set in X
 * NOT : Is Y not set in X
 * SET : Set Y in X
 * UNSET : Unset Y from X
*/

# define RL_IS(X, Y) (X & Y)
# define RL_NOT(X, Y) (!RL_IS(X, Y))
# define RL_SET(X, Y) (X |= Y)
# define RL_UNSET(X, Y) (X &= ~Y)

/*
 * Possible bit for t_line.bitset
 *
 * FINISH : bit to terminate and flush the readline
 * STACK : bit to stack the current line and begin another one
 * INSERT : bit to toogle insert-mode/replace-mode
 * SELECT : bit to toogle extend-video-area-mode/clear-video-area-mode
 * ESC : bit to escape quoting and new line
 * QUOTE : bit to toogle quote-terminated-mode/quote-not-terminated-mode
 * DQUOTE : bit to toogle dquote-terminated-mode/dquote-not-terminated-mode
 * QUOTING : Regroup ESC, QUOTE and DQUOTE
*/

# define RL_FINISH		(1 << 0)
# define RL_STACK		(1 << 1)
# define RL_INSERT		(1 << 2)
# define RL_SELECT		(1 << 3)
# define RL_ESC			(1 << 4)
# define RL_QUOTE		(1 << 5)
# define RL_DQUOTE		(1 << 6)
# define RL_QUOTING		(RL_ESC | RL_QUOTE | RL_DQUOTE)

typedef struct s_data		t_data;
typedef struct s_line		t_line;
typedef struct s_input		t_input;
typedef int					(*t_input_function)(t_line *, long int);

/*
 *	Interactive line data:
 *
 *	bitset : global/local state and settings for readline
 *	prompt : current prompt
 *	input : destination buffer
 *	pos : cursor position in the destination buffer
 *	size : allocated size of the destination buffer
 *	used : actual used size in the destination buffer
 *	select : start position of the video (aka selected) area in the destination buffer
 *	clipboard : duplication of the copied/cuted part of the destination buffer
 *	stack : list of stacked line. (lines are stacked when a quoted (or escaped) new line appear)
*/

struct s_line
{
	int						bitset;
	char					*prompt;
	char					*input;
	char					*clipboard;
	int						pos;
	int						size;
	int						used;
	int						select;
	t_curs					curs;
	t_list					*stack;
	t_dlist					*history;
};

/*
 * Input data:
 * code : input identifier
 * function : input handler
*/

struct s_input
{
	long int				code;
	t_input_function		function;
};

# include "minishell.h"

/*
 * Readline setup/cleanup/teardown
*/

int							rl_setup(t_line *line);
int							rl_cleanup(t_line *line);
void						rl_teardown(t_line *line);

/*
 * Dynamic allocated buffer manipulation
*/

int							input_maj(t_line *line, char *str, int size);
int							input_move(t_line *line, char *str, int size);
void						input_remove(t_line *line, int size);

/*
 * Readline internal function
*/

void						rl_set_prompt(t_line *line);
void						rl_put_prompt(t_line *line);
int							rl_previous_word(t_line *line);
int							rl_next_word(t_line *line);
int							rl_clipboard_new(t_line *line);
int							rl_clipboard_new_cut(t_line *line);
void						rl_toogle_bitset(t_line *line, int set);
int							rl_finish(t_line *line);
int							rl_stack_line(t_line *line);
int							rl_merge_line(t_line *line);

/*
 * Realine display functions:
 * 
 * reset_display : Redraw the interactive buffer and replace the cursor
 * 				   based on t_line.input, t_line.pos and t_line.select .
 * reset_display_ante : Redraw before the cursor position.
 * reset_display_post : Redraw after the cursor position.
*/

void						rl_reset_display(t_line *line);
void						rl_reset_display_ante(t_line *line);
void						rl_reset_display_post(t_line *line);

/*
 * input handler functions
 *
 * An handler use curs_<utilities-function> to manipulate the cursor position
 * and recalc t_line.pos based on the cursor movement.
 *
 * An handler can also modify the content of the destination buffer.
 * If it do so, it must reset all display that appear
 * after the first index of that modification.
 * If t_line.pos is that index, rl_reset_display_post can simply do the work.
*/

int	rl_default_function(t_line *line, long int input);	/* Not handled input */
int	rl_esc_function(t_line *line, long int input);		/* Backslash */
int	rl_quote_function(t_line *line, long int input);	/* Simple quote */
int	rl_dquote_function(t_line *line, long int input);	/* Double quote */
int	rl_nl_function(t_line *line, long int input);		/* New line */
int	rl_comp_function(t_line *line, long int input);		/* Tabulation */
int	rl_left_function(t_line *line, long int input);		/* Left move */
int	rl_right_function(t_line *line, long int input);	/* Right move */
int	rl_wleft_function(t_line *line, long int input);	/* Word left move */
int	rl_wright_function(t_line *line, long int input);	/* Word right move */
int	rl_home_function(t_line *line, long int input);		/* Home move */
int	rl_end_function(t_line *line, long int input);		/* End move */
int	rl_pageup_function(t_line *line, long int input);	/* Pageup move */
int	rl_pagedown_function(t_line *line, long int input);	/* Pagedown move*/
int	rl_select_left_function(t_line *line, long int input);	/* Left extend video area */
int	rl_select_right_function(t_line *line, long int input);	/* Right extend video area */
int	rl_select_wleft_function(t_line *line, long int input);	/* Word left extend video area */
int	rl_select_wright_function(t_line *line, long int input);	/* Word right extend video area */
int	rl_select_home_function(t_line *line, long int input);		/* Home extend video area */
int	rl_select_end_function(t_line *line, long int input);		/* End extend video area */
int	rl_select_pageup_function(t_line *line, long int input);	/* Pageup extend video area */
int	rl_select_pagedown_function(t_line *line, long int input);	/* Pagedown extend video area */
int	rl_retarr_function(t_line *line, long int input);			/* Remove before the cursor */
int	rl_suppr_function(t_line *line, long int input);			/* Remove after the cursor */
int	rl_clear_function(t_line *line, long int input);			/* Clear screen */
int	rl_copy_function(t_line *line, long int input);				/* Copy selected area or current cursor line */
int	rl_cut_function(t_line *line, long int input);				/* Cut selected area or current cursor line */
int	rl_paste_function(t_line *line, long int input);			/* Paste copied/cuted area */
int	rl_insert_function(t_line *line, long int input);			/* Toogle insert-mode/replacement-mode */

int							ft_readline(t_line *line);

#endif
