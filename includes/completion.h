/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:13:04 by alao              #+#    #+#             */
/*   Updated: 2017/03/08 13:46:51 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLETION_H
# define COMPLETION_H

# include "minishell.h"
#define RETARDED_BEHAVIOR	0

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
**    start : See below.
**  between : See below.
**    trail : See below.
** cutpoint : See below.
**   prompt : Size of the prompt.
**     c_sx : Size of the longest word from the list.
**     c_sy : Size of the list in number of item.
**  c_pline : Number of item per line when printing.
**   c_line : Number of line required to move to terminal up.
**    win_x : Size of the window in length.
**    win_y : Size of the window in height.
**      key : The keypressed lastly.
** isfolder : If the match is a folder. boolean.
**      lst : List of the item corresponding to the completion.
**
** The complete command is cutted as follow using the command as exemple:
**
**          Exemple: [ ls / ; cd (tab) ; pwd ]
**
**                                   (int)cutpoint
**                                       |
**                                       |
**  Become:  [ls / ;]         [ ]         [cd ]         [ ; pwd]
**            |                |           |              |
**            |                |           |              |
**     (char *)start   (char *)between   (char *)rcmd   (char *)trail
*/

typedef struct				s_comp
{
	char					*rcmd;
	int						ircmd;
	char					*cpath;
	char					*match;
	char					*home;
	char					*pwd;
	char					*start;
	char					*between;
	char					*trail;
	int						cutpoint;
	int						prompt;
	int						c_sx;
	int						c_sy;
	int						c_pline;
	int						c_line;
	int						win_x;
	int						win_y;
	int						key;
	int						isfolder;
	int						isrematch;
	t_clst					*lst;
}							t_comp;

/*
** Main autocompletion engine:
**        completion : Main function.
**            c_init : Initialization.
**        c_matching : Dispatcher for binary or local files.
**     c_seek_binary : Search binary using env PATH.
**      c_seek_files : Solve path and search.
**          c_parser : Parser.
**          c_sizing : Determine the size of the column/line.
*/

int							completion(long int key);
void						c_init(t_data *s, long int input);
int							c_matching(t_data *s, t_comp *c);
int							c_seek_binary(t_data *s, t_comp *c);
int							c_seek_files(t_data *s, t_comp *c);
int							c_parser(t_comp *c, char *path, char *name);
int							c_sizing(t_comp *c);

/*
** Output functions:
**
**         c_updater : Output the result to struct data.
**            c_gtfo : Keypress handling.
**         c_rematch : Restart on keypress.
*/

int							c_updater(t_comp *c, char *select);
int							c_gtfo(t_comp *c, long int keypress);
int							c_rematch(t_comp *c, long int keypress);

/*
** Terminal functions:
**
**    c_term_mv_down : Make space for the list.
**    c_term_mv_back : Reset the cursor position.
**      c_term_clear : Delete the list from the terminal.
**     c_term_resize : Refresh win_x and win_y.
**         c_printer : Printer of the list.
*/

void						c_term_mv_down(t_comp *c);
void						c_term_mv_back(t_comp *c);
void						c_term_clear(t_comp *c);
int							c_term_resize(t_comp *c);
void						c_printer(t_comp *c);

/*
** Support functions:
**
**           c_clear : Memory clearing.
**       c_clear_lst : List clearing.
**       path_solver : Solve abstract path to absolute.
*/

int							c_clear(t_data *s);
int							c_clear_lst(t_comp *c);
char						*path_solver(t_comp *c, char *cmd, char *cwd);
int							c_spacing_escape(t_clst *node, int x, int o);
int							c_spacing_clear(t_comp *c);
int							ft_sstrlen(char **s);
char						*ft_sstrtostr(char **s, char *sep);

#endif
