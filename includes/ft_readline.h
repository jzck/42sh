/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:02:25 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/19 16:47:18 by gwojda           ###   ########.fr       */
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

typedef struct	s_line
{
	char					*input;
	int						prompt_size;
}				t_line;

typedef struct	s_list_history
{
	char					*str;
	struct s_list_history	*prev;
	struct s_list_history	*next;
}				t_list_history;

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
void			ft_del_2(char **str, size_t *i);
void			ft_del_1(char **str, size_t *i);
void			ft_suppr_2(char **str, size_t *i);
void			ft_suppr_1(char **str, size_t *i);
void			ft_print(char **str, int ret, size_t *i);
void			ft_move_to_line(int ret, size_t *pos, char *str);
void			ft_get_head(t_list_history **head);
void			ft_push_back_history(t_list_history **head, t_list_history *new);
t_list_history	*ft_create_history_list(char *str);
void			ft_curse_move(char *str);
void			ft_move_suppr(char *str, size_t pos);
void			ft_move_dell(char *str, size_t pos);
void			ft_move_to_word(int ret, size_t *pos, char *str);
void			ft_history(char **str, int ret, t_list_history **head);
void			ft_move_term(int ret, size_t *pos, char *str);
void			ft_move_left(size_t pos, char *str);
void			ft_home_end(char *str, int ret, size_t *pos);
int				ft_put(int nb);
char			**ft_split_whitespaces(char const *s);
void			ft_cxv(int ret, size_t *pos, char **str);
char			*ft_lecture(t_list_history *head);
void			ft_prompt(void);


#endif
