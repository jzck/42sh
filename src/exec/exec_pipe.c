#include "exec.h"

int		exec_pipe(t_btree *ast)
{
	int		filedes[2];

	pipe(filedes);
	ft_debug();
	dup2(filedes[1], 1);
	ft_debug();
	ft_exec(ast->left);
	close(filedes[1]);
	dup2(filedes[0], 0);
	ft_exec(ast->right);
	close(filedes[0]);
	return (0);
}
