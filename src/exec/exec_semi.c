#include "exec.h"

int		exec_semi(t_btree *ast)
{
	ft_exec(ast->left);
	ft_exec(ast->right);
	return (0);
}
