/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:31:18 by wescande          #+#    #+#             */
/*   Updated: 2017/03/24 18:38:35 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_H
# define GLOB_H

# define CH(x) ((char **)(x)->content)
# define UCH(x) ((unsigned char **)(x)->content)
# define SCH(x) ((char **)(x).content)
# define SUCH(x) ((unsigned char **)(x).content)

typedef struct	s_ld
{
	void			*content;
	struct s_ld		*next;
	struct s_ld		*prev;
}				t_ld;

typedef struct	s_glob
{
	short int			found;
	short int			cur_dir;
	char				*pat;
	unsigned char		*esc;
	unsigned char		*esc2;
	t_ld				*match;
	t_ld				*match_tmp;
	t_ld				*m_pat;
}				t_glob;

typedef struct	s_expand
{
	t_ld			**wk;
	char			*str;
	unsigned char	*esc;
	char			**split;
	unsigned char	**m_esc;
	char			*s1;
}				t_expand;

typedef struct	s_bquote
{
	t_ld			**wk;
	char			*str;
	unsigned char	*esc;
	unsigned char	*esc2;
	char			*s1;
	char			*s2;
	char			*mid;
}				t_bquote;
/*
** interface of glob.
*/
char			**glob(char *str, unsigned char *esc,
										unsigned char *dbl_esc, int do_match);
void			esc_print(int fd, char *str, unsigned char *esc);
int				word_is_assignment(char **content);
void			*tab_esc_copy(void *content);
char			*get_output(char *command);

/*
** return TRUE if path file is a directory.
*/

int				is_directory(const char *path);

/*
** return TRUE if char at str_pos in ini_str is escape.
** five the possibility to set if the char is esc or not.
*/
int				is_char_esc(const unsigned char *esc,
							const char *ini_str, const char *str_pos);
void			set_char_esc_mode(unsigned char *esc,
							const char *ini_str, const char *str_pos, int mode);
void			set_char_esc(unsigned char *esc,
							const char *ini_str, const char *str_pos);
void			set_char_no_esc(unsigned char *esc,
							const char *ini_str, const char *str_pos);

/*
** Internal function.
*/
unsigned char	*ft_sub_esc(const unsigned char *esc, int start, int len);
unsigned char	*dup_char_esc(const unsigned char *esc, const int size);
unsigned char	*calc_expand_esc(const unsigned char *esc,
								int nb_start, int *nb_middle, int *nb_end);
void			modify_esc_split(unsigned char *esc_dest,
								unsigned char *esc_src, int start, int len);
void			expand_brace(t_glob *tglob);
void			expand_bquote(t_glob *gl);
void			expand_home(t_glob *gl, char *str);
void			expand_var(t_glob *tglob);
void			expand_home(t_glob *gl, char *str);
int				match_pattern(t_glob *tglob, char *str, char *full_word);
int				dir_research(t_glob *tglob, char *p, char *pat, int *mode);
char			**gen_tab(const char *pat, const unsigned char *esc,
				const unsigned char *esc2, int dup);
char			**ft_strsplit_spe(const char *str,
								const unsigned char *esc, char c);
unsigned char	**ft_strsplit_esc(const char *str,
								const unsigned char *esc, char c);

#endif
