/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line-editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:38:21 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 13:44:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITING_H
# define LINE_EDITING_H

# include "minishell.h"
# include <curses.h>
# include <term.h>

# define SHELL_PROMPT	"$> "
# define BUFF_SIZE		32
# define READ_BUF		32
# define FT_KEY_C_C		"\x3"
# define FT_KEY_C_D		"\x4"
# define FT_KEY_C_H		"\x8"
# define FT_KEY_TAB		"\x9"
# define FT_KEY_ENTER	"\xa"
# define FT_KEY_C_K		"\xb"
# define FT_KEY_C_L		"\xc"
# define FT_KEY_C_U		"\x15"
# define FT_KEY_C_Z		"\x1a"
# define FT_KEY_ESC		"\x1b"
# define FT_KEY_UP		"\x1b\x5b\x41"
# define FT_KEY_DOWN	"\x1b\x5b\x42"
# define FT_KEY_RIGHT	"\x1b\x5b\x43"
# define FT_KEY_LEFT	"\x1b\x5b\x44"
# define FT_KEY_C_UP	"\x1b\x4f\x41"
# define FT_KEY_C_DOWN	"\x1b\x4f\x42"
# define FT_KEY_C_RIGHT	"\x1b\x4f\x43"
# define FT_KEY_C_LEFT	"\x1b\x4f\x44"
# define FT_KEY_SQUOTE	"\x22"
# define FT_KEY_DQUOTE	"\x27"
# define FT_KEY_BSLASH	"\x5c"
# define FT_KEY_DEL		"\x7f"

enum	e_qstate
{
	Q_NONE,
	Q_QUOTE,
	Q_DQUOTE,
	Q_BACKSLASH,
};

typedef struct s_data	t_data;
typedef enum e_qstate	t_qstate;

extern t_stof	g_keys[];

int		ft_interactive_sh(t_data *data);
int		input_init(t_data *data);
int		ft_set_termios(t_data *data, int input_mode);
int		ft_prompt(void);

int		ft_history_add(t_data *data);

int		ft_clear_line(t_data *data, char *buf);
int		ft_line_up(t_data *data, char *buf);
int		ft_line_down(t_data *data, char *buf);
int		ft_line_start(t_data *data, char *buf);
int		ft_line_end(t_data *data, char *buf);

int		ft_key_del(t_data *data, char *buf);
int		ft_key_enter(t_data *data, char *buf);
int		ft_key_ctrl_d(t_data *data, char *buf);
int		ft_key_ctrl_c(t_data *data, char *buf);
int		ft_key_default(t_data *data, char *buf);

int		ft_history_up(t_data *data, char *buf);
int		ft_history_down(t_data *data, char *buf);
int		ft_cursor_left(t_data *data, char *buf);
int		ft_cursor_right(t_data *data, char *buf);
int		ft_word_left(t_data *data, char *buf);
int		ft_word_right(t_data *data, char *buf);

void	qstate_none(t_qstate *new, char c);
void	qstate_quote(t_qstate *new, char c);
void	qstate_dquote(t_qstate *new, char c);

#endif
