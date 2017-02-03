/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:13:04 by alao              #+#    #+#             */
/*   Updated: 2017/02/03 12:23:05 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLETION_H
# define COMPLETION_H

# include "minishell.h"

/*
** Autocompletion list for the valid candidates from the parser.
**       id : ID of the item.
**     name : Name of the item.
**     type : Type of the item.
**      len : Length of the name.
**   cursor : Boolean to know which item is currently selected.
**     next : Pointer to the next item of the list.
**     prev : Pointer to the previous item of the list.
*/

typedef struct				s_clst
{
	int						id;
	char					*name;
	int						type;
	int						len;
	int						cursor;
	struct s_clst			*next;
	struct s_clst			*prev;
}							t_clst;

/*
** Autocompletion structure composed as follow:
**     rcmd : The raw command from the begining to the cursor position.
**    ircmd : Cursor position.
**    cpath : Placeholder for the solved path. Later used for the parser.
**    match : Part of the command to match when searching.
**     home : Path to home for the ~ solving.
**      pwd : Current folder to solve local path.
**    trail : The rest of the command after the position.
**   prompt : Size of the prompt.
**     c_sx : Size of the longest word from the list.
**     c_sy : Size of the list in number of item.
**  c_pline : Number of item per line when printing.
**   c_line : Number of line required to move to terminal up.
**    win_x : Size of the window in length.
**      lst : List of the item corresponding to the completion.
*/

typedef struct				s_comp
{
	char					*rcmd;
	int						ircmd;
	char					*cpath;
	char					*match;
	char					*home;
	char					*pwd;
	char					*trail;
	int						prompt;
	int						c_sx;
	int						c_sy;
	int						c_pline;
	int						c_line;
	int						win_x;
	int						key;
	t_clst					*lst;
}							t_comp;

int							completion(long int key);
void						c_init(t_data *s, long int input);
int							c_matching(t_data *s, t_comp *c);
int							c_seek_binary(t_data *s, t_comp *c);
int							c_seek_files(t_data *s, t_comp *c);
int							c_parser(t_comp *c, char *path, char *name);
int							c_sizing(t_comp *c);

int							c_single(t_comp *c);

void						c_term_mv_down(t_comp *c);
void						c_term_mv_back(t_comp *c);
void						c_printer(t_comp *c);

int							c_clear(t_data *s);
char						*path_solver(t_comp *c, char *cmd, char *cwd);

int							 test(t_comp *c);

#endif
