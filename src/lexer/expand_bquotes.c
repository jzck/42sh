/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:46:27 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 20:45:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		expand_bquotes(t_list **alst)
{
	t_list	*new_word;
	t_list	*after_word;
	t_list	*cur_word;
	t_list	*lst;
	t_token	*token;
	t_token	*token_buf;
	char	*word;
	char	*ifs;
	char	*output;
	char	*last_char;
	char	*bq_start;
	char	*bq_end;
	char	*after_bq;
	char	**str;
	t_lexer	lexer;
	t_flag	tk;

	tk = TK_WORD;
	cur_word = *alst;
	while (cur_word && (lst = ft_lst_find(cur_word, &tk, token_cmp_type)))
	{
		cur_word = lst;
		after_word = cur_word->next;
		token = cur_word->content;
		str = &token->data;
		if (!(bq_start = ft_strchr(*str, '`')))
		{
			cur_word = cur_word->next;
			continue ;
		}
		if (!(bq_end = ft_strchr(bq_start + 1, '`')))
		{
			ft_dprintf(2, "{red}%s: parse error near '`'{eoc}\n", SHELL_NAME);
			return (-1);
		}
		*bq_end = 0;
		after_bq = ft_strdup(bq_end + 1);
		word = command_getoutput(bq_start + 1);
		output = word;
		last_char = word + ft_strlen(word) - 1;
		while (*last_char == '\n')
			*last_char++ = 0;
		ifs = ft_getenv(data_singleton()->env, "IFS");
		if (ifs)
			word = ft_strtok(word, ifs);
		*bq_start = 0;
		ft_strappend(str, word);
		while (ifs && (lexer.str = ft_strtok(NULL, ifs)))
		{
			lexer.pos = 0;
			token_buf = token_init();
			token_buf->type = TK_WORD;
			while (lexer.str[lexer.pos])
			{
				token_append(token_buf, &lexer, 0, 0);
				lexer.pos++;
			}
			new_word = ft_lstnew(token_buf, sizeof(*token_buf));
			cur_word->next = new_word;
			new_word->next = after_word;
			cur_word = new_word;
		}
		token = cur_word->content;
		ft_strappend(&token->data, after_bq);
		ft_strdel(&after_bq);
		ft_strdel(&output);
		cur_word = after_word;
	}
	return (0);
}

