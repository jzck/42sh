/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:46:27 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/20 14:17:03 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		bquotes_insert_words(t_list *cur_word, char *word, char *after_bq, char *ifs)
{
	t_list	*new_word;
	t_list	*after_word;
	t_token	*token;

	after_word = cur_word->next;
	if (ifs)
		word = ft_strtok(word, ifs);
	token = cur_word->content;
	token_append_str(token, word, 0, 0);
	if (ifs)
		while ((word = ft_strtok(NULL, ifs)))
		{
			token = token_init();
			token->type = TK_WORD;
			token_append_str(token, word, 0, 0);
			new_word = ft_lstnew(token, sizeof(*token));
			cur_word->next = new_word;
			new_word->next = after_word;
			cur_word = new_word;
		}
	token = cur_word->content;
	ft_strappend(&token->data, after_bq);
	return (0);
}

int		bquotes_substitute(t_list *cur_word, char *bq_start, char *bq_end)
{
	char	*output;
	char	*last_char;
	char	*after_bq;
	char	*ifs;
	t_token	*token;

	*bq_start = 0;
	*bq_end = 0;
	if ((output = command_getoutput(bq_start + 1)))
	{
		last_char = output + ft_strlen(output) - 1;
		while (*last_char == '\n')
			*last_char++ = 0;
	}
	DG("output = [%s]", output);
	after_bq = ft_strdup(bq_end + 1);
	token = cur_word->content;
	ifs = is_char_esc(token->esc, token->data, bq_start) ?
		NULL : ft_getenv(data_singleton()->env, "IFS");
	bquotes_insert_words(cur_word, output ? output : "", after_bq, ifs);
	ft_strdel(&output);
	ft_strdel(&after_bq);
	return (0);
}

int		bquotes_expand(t_list **alst)
{
	(void) alst;
	/*
	t_list	*cur_word;
	char	*bq_start;
	char	*bq_end;
	t_flag	tk_word;
	t_token	*token;

	tk_word = TK_WORD;
	cur_word = *alst;
	while ((cur_word = ft_lst_find(cur_word, &tk_word, token_cmp_type)))
	{
		token = cur_word->content;
		if (!(bq_start = ft_strchr(token->data, '`'))
				|| is_char_esc(token->esc2, token->data, bq_start))
		{
			cur_word = cur_word->next;
			return (0);
		}
		if (!(bq_end = ft_strchr(bq_start + 1, '`')))
		{
			ft_dprintf(2, "{red}%s: parse error near '`'{eoc}\n", SHELL_NAME);
			return (-1);
		}
		if (bquotes_substitute(cur_word, bq_start, bq_end))
			return (-1);
		if (!(*token->data))
			ft_lst_delif(alst, cur_word->content, ft_addrcmp, token_free);
		cur_word = *alst;
	}
	*/
	return (0);
}

