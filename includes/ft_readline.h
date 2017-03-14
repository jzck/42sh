/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:35:44 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/14 13:47:09 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# include <sys/ioctl.h>
# include <termios.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <term.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <dirent.h>
# include <locale.h>

# include "ft_input.h"

# define FLECHE_HAUT 4283163
# define FLECHE_BAS 4348699
# define FLECHE_GAUCHE 4479771
# define FLECHE_DROITE 4414235
# define TOUCHE_DELETE 2117294875
# define TOUCHE_CTRL_C 3
# define TOUCHE_CTRL_D 4
# define TOUCHE_CTRL_L 12
# define TOUCHE_CTRL_R 18
# define TOUCHE_SUPPR 127
# define TOUCHE_HOME 4741915
# define TOUCHE_END 4610843
# define TOUCHE_TAB 9
# define TOUCHE_OPT_RIGHT 1130044187
# define TOUCHE_OPT_LEFT 1146821403
# define TOUCHE_OPT_UP 1096489755
# define TOUCHE_OPT_DOWN 1113266971
# define TOUCHE_OPT_V 10127586
# define TOUCHE_OPT_C 42947
# define TOUCHE_OPT_X 8948194
# define TOUCHE_F5 892427035
# define TOUCHE_F6 925981467

# define CORRUPT 1

/* # define IS_QUOTES (1 << 0) */
/* # define IS_BQUOTES (1 << 1) */
/* # define IS_DQUOTES (1 << 2) */
/* # define IS_BSLASH (1 << 3) */
/* # define IS_ACCOLADE (1 << 4) */
/* # define IS_BRACKET (1 << 5) */

# define STR data_singleton()->line.input
# define POS data_singleton()->line.pos

# define HIST 1

# define ERROR_CNTL_R 1

typedef struct	s_list_history
{
	char					*str;
	struct s_list_history	*prev;
	struct s_list_history	*next;
}				t_list_history;

typedef struct	s_line
{
	char					*input;
	char					*copy_tmp;
	size_t					pos;
	int						prompt_size;
	int						list_size;
	char					opt;
	char					is_prompt;
	t_list_history			*list_end;
	t_list_history			*list_cur;
	t_list_history			*list_beg;
}				t_line;

typedef struct	s_key
{
	int		value;
	void	(*f)(void);
}				t_key;

extern t_key			g_keys[];

void			ft_reset_tab(char *tabl);
void			ft_putnc(char c, int n);
int				ft_nbr_len(int nbr);
void			ft_puttermcaps(char *str);
void			ft_get_beggin_with_curs(char *str, size_t *pos);
void			ft_check_end_of_line(char *str, size_t pos);
int				ft_size_term(void);
void			ft_add_in_history_file(char *str);
void			ft_get_beggin(char *str, size_t *pos);
void			ft_get_next_str(char *str, size_t *pos);
void			ft_putall_current_str(char *str, size_t *pos);
void			ft_current_str(char *str, size_t pos);
int				ft_strlen_next(char *str, size_t pos);
void			ft_push_back_history(t_list_history **head, t_list_history *new);
void			ft_prompt(void);
char			*ft_remove_imput(char *str, size_t pos);
char			*ft_realloc_imput(char *str, int a, size_t pos);
char			*ft_strdupi(char const *s);
char			*ft_strndup(char const *s, int n);
t_list_history	*ft_create_history_list(char *str);
char			*ft_strdupi_w(char const *s);
void			ft_realloc_str_history(char **str, size_t pos, int nb_his, int len);
void			ft_realloc_str_history_2(char **str, size_t pos, char *s);
long long		ft_pow(int nbr, int power);
void			ft_realloc_str_history_3(char **str, size_t pos, char *s);
char			*ft_strget_history(char *str);
int				ft_nb_last_line(char *str, size_t pos);
int				ft_put(int nb);
void			ft_check_line(void);
void			ft_clear_window(void);
void			free_history_list(t_list_history *head);
int				ft_nb_of_line(char *str, size_t pos);
int				ft_get_size_prev(char *str, size_t pos);
void			sigwinch_resize(int sig);

char			*ft_read_stdin(void);
void			ft_end(void);
void			ft_home(void);
void			ft_move_right(void);
void			ft_move_left(void);
void			ft_up(void);
void			ft_down(void);
void			ft_buff_f6(void);
void			ft_control_d(void);
void			ft_control_c(void);
void			ft_control_l(void);
void			ft_del(void);
void			ft_suppr(void);
void			ft_print(int ret);
void			ft_surch_in_history(void);
void			ft_printall(void);
void			ft_history_down(void);
void			ft_history_up(void);
void			ft_found_next_word(void);
void			ft_found_prev_word(void);
void			ft_c(void);
void			ft_x(void);
void			ft_v(void);
void			ft_read_it(int input, size_t *pos, char **str);
int				readline(int fd, int prompt, char **input);
int				ft_completion(int ret);

struct termios	*ft_save_termios(int save);

char			*ft_strdupi_w(char const *s);

void			ft_add_str_in_history(char *str);
void			ft_init_history(void);
char			*ft_history_parsing(void);
struct termios	*ft_save_termios(int save);
void			ft_init_termios(void);
void			readline_init(int prompt);

#endif
