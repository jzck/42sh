#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
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
# define FT_KEY_DEL		"\x7f"

typedef struct	s_stof
{
	char	*name;
	int		(*f)();
}				t_stof;

typedef struct	s_data
{
	char	**env;
	t_dlist	*history;
	t_dlist	*input_mem;
}				t_data;

extern t_stof	g_builtins[];
extern t_stof	g_keys[];

typedef	int		key_press(t_data *data, t_dlist **input_chain, char *buf);

int		ft_tc_init(t_data *data);
int		ft_interactive_sh(t_data *data);
int		ft_input_is_escaped(t_dlist *input_chain);
int		ft_history_add(t_data *data, t_dlist *input_chain);

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

int		ft_cmd_process(char **argv, char ***env_p);
int		ft_cmd_exec(char *execpath, char **argv, char ***env_p);
char	**ft_cmd_getav(char *cmd);

int		ft_builtin(char **av, char ***env);
int		builtin_echo(char **av, char ***env);
int		builtin_cd(char **av, char ***env);
int		builtin_cd_opts(char **av, int *opts);
char	*builtin_cd_special(char **av, char **env);
int		builtin_exit(char **av, char ***env);
int		builtin_setenv(char **av, char ***env);
int		builtin_unsetenv(char **av, char ***env);
int		builtin_env(char **av, char ***env);

void	ft_expand_dollar(char **av, char **env);
char	*ft_env_getval(char **env, char *key);

int		ft_path_access(char *execpath, char *execname);
char	*ft_path_findexec(char **path, char *execname);

#endif
