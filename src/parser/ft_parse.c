/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:14:58 by jhalford          #+#    #+#             */
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
	if (sym == CMD_SUPERIOR || sym == PIPE_SEMI_SEQUENCE
		|| sym == COMPLETE_COMMANDS || sym == END_COMMAND)
		return (1);
	return (0);
}

int			ft_parse(t_btree **ast, t_list **token, t_parser *parser)
{
	while (*token)
	{
		produce_sym(*parser->stack, parser->new_sym, token);
		//DG("new sym %s", read_state(*parser->new_sym));

		if (eval_sym(*parser->stack, *parser->new_sym))
			return ((parser->state = ERROR));
		else
		{
			aggregate_sym(&parser->stack, parser->new_sym, &parser->state);
			push_stack(++parser->stack, *parser->new_sym);
		}
//		ft_read_stack(parser->stack);
		DG("\n");
		if (*parser->stack == PROGRAM)
			parser->state = SUCCESS;
		else
			parser->state = UNDEFINED;
		build_tree(ast, token);
	//	btree_print(STDBUG, *ast, &ft_putast);
		if ((end_instruction(*parser->stack) && !(*token)->next))
			insert_linebreak(token);
		else
			ft_lst_delif(token, (*token)->content, &ft_addrcmp, &token_free);
	}
	if (parser->state == SUCCESS)
		DG("sucessful parsing");
	return (0);
}
