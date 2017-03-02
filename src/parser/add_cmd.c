/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
" ============================================================================
" Netrw Directory Listing                                        (netrw v140)
"   /Users/antoineriard/42sh
"   Sorted by      name
"   Sort sequence: [\/]$,\<core\%(\.\d\+\)\=\>,\.h$,\.c$,\.cpp$,*,\.o$,\.obj$,\.info$,\.swp$,\.bak$,\~$
"   Quick Help: <F1>:help  -:go up dir  D:delete  R:rename  s:sort-by  x:exec
" ============================================================================
../
.git/
includes/
libft/
pdf/
sample/
src/
.gitignore
.gitmodules
.tags
.valgrind.supp
Makefile
STDBUG
donovan_segaults_06-02
update_makefile.sh*
.swp
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:49:15 by ariard            #+#    #+#             */
/*   Updated: 2017/02/25 18:50:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			add_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;
	char		**my_tab;

	DG("add cmd");
	if ((token = (*lst)->content)->type == TK_IN || token->type == TK_PAREN_OPEN)
		return (0);
	else if (!*ast)
		gen_node(ast);
	else if (isdir(ast, lst))
		return (add_file(ast, lst));
	else if (isloop(ast, lst) == 3)
		return (add_loop_condition(ast, lst));
	else if (isloop(ast, lst))
		return (add_loop_cmd(ast, lst));
	else if (iscondition(ast, lst) == 1)
		return (add_condition_cmd(ast, lst));
	else if (iscondition(ast, lst) == 2)
		return (add_branch(ast, lst));
	else if (iscase(ast, lst) == 1)
		return (add_pattern(ast, lst));
	else if (iscase(ast, lst) == 2)
		return (add_case_cmd(ast, lst));
	else if (iscase(ast, lst) == 3)
		return (add_branch(ast, lst));
	else if (issubshell(ast, lst))
		return (add_subshell_cmd(ast, lst));
	else if (isfunc(ast, lst))
		return (add_func_cmd(ast, lst));
	else if ((node = (*ast)->item)->type != TK_DO && node->type != TK_THEN
		&& node->type != TK_PAREN_CLOSE)
		return (add_cmd(&(*ast)->right, lst));
	my_tab = NULL;
	node = (*ast)->item;
	node->type = token->type;
	if (token->type == TK_WORD || token->type == TK_ASSIGNEMENT_WORD)
	{
		my_tab = ft_sstradd(my_tab, token->data);
		my_tab = ft_sstradd(my_tab, (char *)token->esc);
		ft_ld_pushback(&node->data.token, my_tab);
	}
	return (0);
}
