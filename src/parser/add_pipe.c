#include "parser.h"

int		add_pipe(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_cmd		*cmd;

	(void)lst;
	node = (*ast)->item;
	ft_lsteadd(&node->data.cmds, ft_lstnew(&cmd, sizeof(cmd)));
	return (0);
} 					
