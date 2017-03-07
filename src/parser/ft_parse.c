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

#include "minishell.h"

static void		insert_linebreak(t_list **lst)
{
	t_token		*token;
	
	token = (*lst)->content;
	token->type = LINEBREAK;
}

static int		end_instruction(t_list **stack)
{
	t_sym		*head;
	
	head = (*stack)->content;
	if (*head == CMD_SUPERIOR || *head == PIPE_SEMI_SEQUENCE
		|| *head == COMPLETE_COMMANDS || *head == END_COMMAND)
		return (1);
	return (0);
}

int			ft_parse(t_btree **ast, t_list **token, t_parser *parser)
{
	t_sym		*head;

	while (*token)
	{
		produce_sym(&parser->stack, parser->new_sym, token);
		DG("new sym %s", read_state(*parser->new_sym));
		if (eval_sym(&parser->stack, *parser->new_sym))
			return ((parser->state = ERROR));
		else
		{
			if (aggregate_sym(&parser->stack, parser->new_sym, &parser->state))
				return (0);
			push_stack(&parser->stack, *parser->new_sym);
		}
//		ft_read_stack(parser->stack);
		DG("\n");
		if (*(head = (parser->stack)->content) == PROGRAM)
			parser->state = SUCCESS;
		else
			parser->state = UNDEFINED;
		build_tree(ast, token);
		btree_print(STDBUG, *ast, &ft_putast);
		if ((end_instruction(&parser->stack) && !(*token)->next))
			insert_linebreak(token);
		else
			ft_lst_delif(token, (*token)->content, &ft_addrcmp, &token_free);
	}
	if (parser->state == SUCCESS)
		DG("sucessful parsing");
	return (0);
}
