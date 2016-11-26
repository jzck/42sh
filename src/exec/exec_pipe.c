#include "exec.h"

int		exec_pipe(t_btree *ast, t_data *data)
{
	int		filedes[2];

	pipe(filedes);
	ft_printf("doing dup2\n");
	if ((dup2(filedes[1], 1)) == -1)
		return (-1);
	ft_exec(ast->left, data);
	close(filedes[1]);
	dup2(filedes[0], 0);
	ft_exec(ast->right, data);
	close(filedes[0]);
	return (0);
}
