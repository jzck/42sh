#include "lexer.h"

void	token_print(t_list *lst)
{
	t_token		*token;

	while (lst)
	{
		token = lst->content;
		ft_printf("%#06llx: '%s'\n", token->type, token->data);
		lst = lst->next;
	}
}
