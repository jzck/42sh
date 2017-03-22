/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_match.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:27:14 by alao              #+#    #+#             */
/*   Updated: 2017/03/22 15:13:12 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Seek the current word.
*/

static char	*c_current_words(t_comp *c)
{
	size_t	pos;
	char	*str;

	(void)c;
	pos = data_singleton()->line.pos;
	str = data_singleton()->line.input;
	DG("pos = \"%zu\"", pos);
	while (pos && str[pos] != ' ' && str[pos] != '<'
	&& str[pos] != '>' && str[pos] != '\n' && str[pos] != ';')
		--pos;
	if (str[pos] == ' ' || str[pos] == '<'
	|| str[pos] == '>' || str[pos] == '\n' || str[pos] == ';')
		++pos;
	DG("pos = \"%zu\"", pos);
	return (str + pos);
}

/*
** Start the parsing for the autocompletion.
*/

int			c_matching(t_data *s, t_comp *c)
{
	char	*current_word;

	DG("c->rcmd = \"%s\"", c->rcmd);
	current_word = c_current_words(c);
	DG("current_word = \"%s\"", current_word);
	if (ft_strchr(c->rcmd, '/'))
		c_seek_abs_path(c, current_word);
	else if (ft_strchr(c->rcmd, '$'))
		c_seek_env(c, current_word);
	else if (c->rcmd[0] != '.' && !(ft_strchr(c->rcmd, ' ')))
		c_seek_binary(s, c);
	else
		c_seek_files(s, c, current_word);
	if (s->comp && s->comp->lst)
	{
		c_sizing(c);
		return (1);
	}
	return (0);
}
