/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:11:48 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/01 16:19:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_data			t_data;

typedef long long				t_type;
typedef long long				t_flag;
typedef struct s_line			t_line;
typedef struct s_comp			t_comp;
typedef struct s_exec			t_exec;
typedef struct s_jobc			t_jobc;
typedef enum e_mode				t_mode;

typedef struct s_lexer			t_lexer;
typedef enum e_lexstate			t_lexstate;
typedef struct s_token			t_token;

typedef struct s_ld				t_ld;
typedef struct s_astnode		t_astnode;
typedef struct s_redir			t_redir;
typedef struct s_cmd			t_cmd;
typedef union u_astdata			t_astdata;
typedef union u_word			t_word;
typedef long long				t_type;

typedef int 				t_condition;
typedef struct s_job			t_job;
typedef struct s_execmap		t_execmap;
typedef struct s_redirmap		t_redirmap;
typedef struct s_process		t_process;
typedef int		(t_execf)(const char *path, char *const argv[], char *const envp[]);

typedef int						t_sym;
typedef struct s_parser			t_parser;
typedef enum e_parstate			t_parstate;
typedef struct s_aggrematch		t_aggrematch;
typedef struct s_prodmatch		t_prodmatch;
typedef struct s_stackmatch		t_stackmatch;
typedef struct s_errormatch		t_errormatch;
typedef struct s_treematch		t_treematch;

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
	TK_ASSIGNEMENT_WORD = 50,
	TK_BANG,
	TK_NAME,
	TK_FOR,
	TK_IO_NUMBER,
	TK_DLESSDASH,
	TK_LESSGREAT,
	TK_SUBSHELL,
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
	CMD_SUPERIOR,
	AND_OR_MAJOR,
	AND_OR_MINOR,
	END_COMMAND,
	CONDITION,
	COMPLETE_CONDITION,
	FOR_WORDLIST,
	PATTERN_CASE,
	FUNC_NAME,
	CLOSE_LIST,
	REDIR,
	ALL = 200,
};

#endif
