/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:46:27 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/17 15:48:39 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		bquotes_insert_words(t_list *cur_word, char *word, char *after_bq)
{
	char	*ifs;
	t_list	*new_word;
	t_list	*after_word;
	t_token	*token;

	after_word = cur_word->next;
	ifs = ft_getenv(data_singleton()->env, "IFS");
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
	bquotes_insert_words(cur_word, output ? output : "", after_bq);
	ft_strdel(&output);
	ft_strdel(&after_bq);
	return (0);
}

int		bquotes_expand(t_list **alst)
{
	t_list	*cur_word;
	t_list	*lst;
	char	*bq_start;
	char	*bq_end;
	t_flag	tk;

	tk = TK_WORD;
	cur_word = *alst;
	while ((lst = ft_lst_find(cur_word, &tk, token_cmp_type)))
	{
		cur_word = lst;
		if (!(bq_start = ft_strchr(((t_token*)cur_word->content)->data, '`')))
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
		if (!(*((t_token*)cur_word->content)->data))
			ft_lst_delif(alst, cur_word->content, ft_addrcmp, token_free);
		cur_word = lst;
	}
	return (0);
}

