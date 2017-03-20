#include "minishell.h"

int		pset_until(t_process *p, t_btree *ast)
{
	p->data.d_while.condition = btree_map(ast->left, &node_copy);
	p->data.d_while.content = btree_map(ast->right, &node_copy);
	p->type = PROCESS_UNTIL;
	return (0);
}
