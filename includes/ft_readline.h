/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:35:44 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/26 14:58:14 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

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

# define FLECHE_HAUT 4283163
# define FLECHE_BAS 4348699
# define FLECHE_GAUCHE 4479771
# define FLECHE_DROITE 4414235
# define TOUCHE_DELETE 2117294875
# define TOUCHE_CTRL_C 3
# define TOUCHE_CTRL_D 4
# define TOUCHE_CTRL_R 18
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
	int						prompt_size;
	int						list_size;
	char					opt;
	t_list_history			*list_end;
	t_list_history			*list_beg;
}				t_line;

int		builtin_history(const char *path, char *const av[], char *const envp[]);
void			ft_check_backslash(char **str);
char			*ft_strget_history(char *str);
void			ft_surch_in_history(char **str, size_t *pos);
void			ft_realloc_str_history_3(char **str, size_t pos, char *s);
void			ft_move_right(size_t *pos, char *str);
void			ft_move_left(size_t *pos, char *str);
int				ft_put(int nb);
void			ft_end(char *str, size_t *pos);
void			ft_home(char *str, size_t *pos);
void			ft_realloc_str_history_2(char **str, size_t pos, char *s);
void			ft_realloc_str_history(char **str, size_t pos
				, int nb_his, int len);
char			*ft_strdupi_w(char const *s);
void			ft_history_parsing();
void			ft_check_heredoc(char **str);
void			ft_history_builtin(void);
int				ft_nbr_len(int nbr);
int				ft_found_next_char(char *str, size_t i);
void			ft_check_end_of_line(char *str, size_t pos);
void			ft_printall(char *str, size_t *pos);
void			ft_get_beggin_with_curs(char *str, size_t *pos);
void			ft_history(char **str, int ret, t_list_history **head, size_t *pos);
void			ft_suppr(char **str, size_t *i);
void			ft_del(char **str, size_t *i);
void			ft_current_str(char *str, size_t pos);
int				ft_strlen_next(char *str, size_t pos);
void			ft_putall_current_str(char *str, size_t *pos);
void			ft_get_next_str(char *str, size_t *pos);
void			ft_get_beggin(char *str, size_t *pos);

long long		ft_pow(int nbr, int power);
char			*ft_strndup(char const *s, int n);
char			*ft_strdupi(char const *s);
void			ft_puttermcaps(char *str);
void			ft_putnc(char c, int n);
int				ft_size_term(void);
void			ft_free_tabstr(char ***env);
int				ft_is_whitespaces(char *str);
int				ft_get_size_prev(char *str, size_t pos);
int				ft_nb_line(char *str, size_t pos);
int				ft_get_ind_prev(char *str, size_t pos);
void			ft_found_next_word(char *str, size_t *pos);
void			ft_move_to_beggin(char *str, size_t *pos);
int				ft_nb_last_line(char *str, size_t pos);
void			ft_found_prev_word(char *str, size_t *pos);
char			*ft_remove_imput(char *str, size_t pos);
char			*ft_realloc_imput(char *str, int a, size_t pos);
int				ft_readline(void);
struct termios	*ft_stats_term_termcaps(void);
struct termios	*ft_save_stats_term(void);
void			ft_init_line(void);
void			ft_read_it(int input, size_t *pos, char **str);
void			ft_check_quotes(char **s, t_list_history *head);
int				ft_check_quotes_num(char *s);
void			ft_print(char **str, int ret, size_t *i);
void			ft_move_to_line(int ret, size_t *pos, char *str);
void			ft_get_head(t_list_history **head);
void			ft_push_back_history(t_list_history **head, t_list_history *new);
t_list_history	*ft_create_history_list(char *str);
void			ft_curse_move(char *str);
void			ft_move_suppr(char *str, size_t pos);
void			ft_move_dell(char *str, size_t pos);
void			ft_move_to_word(int ret, size_t *pos, char *str);
void			ft_move_term(int ret, size_t *pos, char *str);
void			ft_home_end(char *str, int ret, size_t *pos);
int				ft_put(int nb);
char			**ft_split_whitespaces(char const *s);
void			ft_cxv(int ret, size_t *pos, char **str);
char			*ft_lecture(t_list_history *head);
void			ft_prompt(void);

#endif
