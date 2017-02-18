/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:30:22 by ariard            #+#    #+#             */
/*   Updated: 2017/02/18 18:06:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		insert_linebreak(t_list **lst)
{
	t_token		*token;

	token = (*lst)->content;
	token->type = LINEBREAK;
}

static int		end_instruction(t_sym sym)
{
	if (sym == CMD_SUPERIOR || sym == PIPE_SEMI_SEQUENCE)
		return (1);
	return (0);
}

int			ft_parse2(t_btree **ast, t_list **token)
{
	t_sym			*new_sym;
	t_sym			*stack;
	t_parstate		state;

	state = UNDEFINED;
	new_sym = ft_memalloc(sizeof(t_sym));
	stack = ft_memalloc(sizeof(t_sym) * 1000);
	push_stack(stack, LINEBREAK);
	while (*token)
	{
		produce_sym(*stack, new_sym, token);	
		DG("new sym %s", read_state(*new_sym));
		if (eval_sym(*stack, *new_sym))
			state = ERROR;
		else
		{	
			aggregate_sym(&stack, new_sym, &state);
			push_stack(++stack, *new_sym);
		}
		ft_putstr("\n");
		ft_read_stack(stack);
		if (*stack == PROGRAM)
			state = SUCCESS;
		if (state == ERROR)
			return (error_syntax(token));		
		if (state == SUCCESS)
			ft_putstr("success");
		build_tree(ast, token);
		btree_print(STDBUG, *ast, &ft_putast);
		if (end_instruction(*stack) && !(*token)->next)
			insert_linebreak(token);
		else
			ft_lst_delif(token, (*token)->content, &ft_addrcmp, &token_free);
	}
	return (0);
}
