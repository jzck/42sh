#include "exec.h"

int		exec_semi(t_btree *ast, t_data *data)
{
	ft_exec(ast->left, data);
	ft_exec(ast->right, data);
	return (0);
}
