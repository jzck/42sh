/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:11:48 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/16 20:13:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <sys/types.h>

# define SH_INTERACTIVE			(1 << 0)
# define SH_OPTS_JOBC			(1 << 1)
# define SH_OPTS_LC				(1 << 2)
# define SH_MODE_INPUT			(1 << 3)
# define SH_MODE_EXEC			(1 << 4)

# define SH_MODE_MASK			(SH_MODE_INPUT | SH_MODE_EXEC)
# define SH_HAS_JOBC(b)			(b & SH_OPTS_JOBC)
# define SH_IS_INTERACTIVE(b)	(b & SH_INTERACTIVE)
# define SH_NO_INTERACTIVE(b)	!(b & SH_INTERACTIVE)

# define SH_MSG_NOJOBC	"no job-control"

typedef long long				t_type;
typedef long long				t_flag;

typedef struct s_data			t_data;
typedef struct s_line			t_line;
typedef struct s_comp			t_comp;
typedef struct s_exec			t_exec;
typedef struct s_jobc			t_jobc;
typedef enum e_mode				t_mode;
typedef struct s_data_template	t_btexport;

/*
**	Lexer types
*/

typedef struct s_lexer			t_lexer;
typedef enum e_lexstate			t_lexstate;
typedef struct s_token			t_token;
typedef struct s_rvwords		t_rvwords;

typedef struct s_ld				t_ld;

/*
**	Execution types
*/

typedef int		 				t_condition;
typedef struct s_job			t_job;
typedef struct s_process		t_process;
typedef int						(t_execf)(const char *path,
		char *const argv[],
		char *const envp[]);
typedef enum e_process_type		t_process_type;
typedef union u_process_data	t_process_data;
typedef	struct s_process_map	t_process_map;
typedef struct s_data_cond		t_data_while;
typedef struct s_data_cond		t_data_if;
typedef struct s_data_cond		t_data_if;


/*
**	Parser types
*/

typedef struct s_astnode		t_astnode;
typedef struct s_redir			t_redir;
typedef struct s_cmd			t_cmd;
typedef union u_astdata			t_astdata;
typedef union u_word			t_word;
typedef struct s_parser			t_parser;
typedef int						t_sym;
typedef enum e_parstate			t_parstate;
typedef struct s_aggrematch		t_aggrematch;
typedef struct s_prodmatch		t_prodmatch;
typedef struct s_stackmatch		t_stackmatch;
typedef struct s_errormatch		t_errormatch;
typedef struct s_treematch		t_treematch;
typedef struct s_distrostree	t_distrostree;

t_data		*data_singleton();

enum	e_sym
{
	LINEBREAK = 1,
	TK_COMMAND,
	TK_LESS,
	TK_GREAT,
	TK_DLESS,
	TK_DGREAT,
	TK_LESSAND,
	TK_GREATAND,
	TK_SEMI,
	TK_PIPE,
	TK_AND_IF,
	TK_OR_IF,
	TK_AMP,
	TK_PAREN_OPEN,
	TK_PAREN_CLOSE,
	TK_BQUOTE,
	TK_NEWLINE,
	TK_WHILE,
	TK_DO,
	TK_DONE,
	TK_IF,
	TK_THEN,
	TK_FI,
	TK_ELIF,
	TK_ELSE,
	TK_UNTIL,
	TK_WORD,
	TK_ASSIGNMENT_WORD = 50,
	TK_BANG,
	TK_NAME,
	TK_FOR,
	TK_IO_NUMBER,
	TK_DLESSDASH,
	TK_LESSGREAT,
	TK_CASE,
	TK_IN,
	TK_ESAC,
	TK_CLOBBER,
	TK_LBRACE,
	TK_RBRACE,
	TK_DSEMI,
	PROGRAM = 100,
	COMPLETE_COMMAND,
	COMPLETE_COMMANDS,
	LIST,
	AND_OR,
	PIPELINE,
	PIPE_SEQUENCE,
	COMMAND,
	COMPOUND_COMMAND,
	SUBSHELL,
	COMPOUND_LIST,
	TERM,
	FOR_CLAUSE,
	NAME,
	IN,
	WORDLIST,
	CASE_CLAUSE,
	CASE_LIST,
	CASE_LIST_NS,
	CASE_ITEM,
	CASE_ITEM_NS,
	PATTERN,
	IF_CLAUSE,
	BRACE_CLAUSE,
	ELSE_PART,
	WHILE_CLAUSE,
	UNTIL_CLAUSE,
	FUNCTION_DEFINITION,
	FUNCTION_BODY,
	FNAME,
	BRACE_GROUP,
	DO_GROUP,
	SIMPLE_COMMAND,
	CMD_NAME,
	CMD_WORD,
	CMD_PREFIX,
	CMD_SUFFIX,
	REDIRECT_LIST,
	IO_REDIRECT,
	IO_FILE,
	FILENAME,
	IO_HERE,
	HERE_END,
	NEWLINE_LIST,
	SEPARATOR_OP,
	SEPARATOR,
	SEQUENTIAL_SEP,
	BRACE,
	LOOP,
	FUNC,
	PIPE_SEMI_SEQUENCE,
	PIPE_CLOSE_SEQUENCE,
	CMD_SUPERIOR,
	SEQUENCE,
	AND_OR_MAJOR,
	AND_OR_MINOR,
	END_COMMAND,
	CONDITION,
	COMPLETE_CONDITION,
	FOR_WORDLIST,
	PATTERN_CASE,
	FUNC_NAME,
	OPEN_FUNC,
	CLOSE_FUNC,
	CLOSE_LIST,
	REDIR,
	CMD,
	HEREDOCDATA,
	HEREDOC_DELIM,
	ALL = 200,
	TERMINUS = 300,
};

/*
** LIST D:
*/

void			ft_ld_new(t_ld **alst, void *content);
t_ld			*ft_ld_front(t_ld	*ld);
void			ft_ld_pushfront(t_ld **alst, void *content);
void			ft_ld_pushback(t_ld **alst, void *content);
size_t			ft_ld_size(t_ld *ld);
void			ft_ld_del(t_ld **ld, void (*del)());
void			ft_ld_clear(t_ld **ld, void (*del)());
void			ft_ld_reverse(t_ld **lst);
t_ld			*ft_ld_back(t_ld *ld);
t_ld			*ft_ld_swap(t_ld *l_cur);
char			**ft_ld_to_tab(t_ld *ld);
t_ld			*ft_ld_order(t_ld *ld, int (*f)());
t_ld			*ft_ld_copy(t_ld *src, void *(*f)(void *elem));

/*
** str:
*/

char			*ft_strjoinf(char *str, char *str2, int mode);
char			*ft_strsubf(char *s, unsigned int start,
							size_t len, short int mode);
void			ft_tabdel(char ***mytab);
int				ft_tablen(char **mytab);

void			*ft_memrealloc(void *ptr, size_t old_s, size_t new_s);

#endif
