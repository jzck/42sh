/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line-editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:38:21 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 14:41:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITING_H
# define LINE_EDITING_H

# include "libft.h"
# include <curses.h>
# include <term.h>

# define SHELL_PROMPT	"$> "
# define BUFF_SIZE		32
# define READ_BUF		32
# define FT_KEY_C_D		"\x4"
# define FT_KEY_C_H		"\x8"
# define FT_KEY_TAB		"\x9"
# define FT_KEY_ENTER	"\xa"
# define FT_KEY_C_K		"\xb"
# define FT_KEY_C_L		"\xc"
# define FT_KEY_C_U		"\x15"
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

typedef struct s_data	t_data;

struct	s_data
{
	char	**env;
	t_dlist	*history;
	t_dlist	*input_mem;
};

extern t_stof	g_keys[];

int		ft_tc_init(t_data *data);
int		ft_interactive_sh(t_data *data);
int		ft_prompt(void);
int		ft_input_is_escaped(t_dlist *input_chain);
int		ft_history_add(t_data *data, t_dlist *input_chain);

typedef	int		key_press(t_data *data, t_dlist **input_chain, char *buf);
key_press	ft_clear_line;
key_press	ft_line_up;
key_press	ft_line_down;
key_press	ft_line_start;
key_press	ft_line_end;
key_press	ft_history_up;
key_press	ft_history_down;
key_press	ft_cursor_left;
key_press	ft_cursor_right;
key_press	ft_word_left;
key_press	ft_word_right;
key_press	ft_key_del;
key_press	ft_key_enter;
key_press	ft_key_basic;
key_press	ft_key_ctrl_d;

#endif
