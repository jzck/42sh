/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_matching.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:27:14 by alao              #+#    #+#             */
/*   Updated: 2017/03/14 17:22:10 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	chevron y es-tu ???
*/

int			c_chevron(t_comp *c)
{
	size_t	pos;

	pos = c->ircmd;
	while (pos)
	{
		if (c->rcmd[pos] == '<' || c->rcmd[pos] == '>')
			return (1);
		--pos;
	}
	if (c->rcmd[pos] == '<' || c->rcmd[pos] == '>')
		return (1);
	return (0);
}

/*
** Start the parsing for the autocompletion.
** Check the first char of the c->rcmd for a . or /. to see if it's a local
** path to search even if there's no space in the command.
** If a space is found in the command. The function will assume it's a binary
** completion that is needed. Else the c_seek_files() is called to search for
** local path along with the binary part separated.
** If any of the other part successfully created a list, the c_sizing is called
** and 1 is returned. The last condition also check is the structure still
** exist. It's only when the c_rematch() called it that it can be the case.
** Else 0 is returned.
*/

static char	*c_current_words(t_comp *c)
{
	int	pos;

	pos = c->ircmd;
	while (pos && c->rcmd[pos] != ' ')
		--pos;
	if (c->rcmd[pos] == ' ')
		++pos;
	return (c->rcmd + pos);
}

int			c_matching(t_data *s, t_comp *c)
{
	char	*current_word;

	current_word = c_current_words(c);
	if (ft_strchr(c->rcmd, '/'))
		c_seek_abs_path(c, current_word);
	else if (ft_strchr(c->rcmd, '$'))
		c_seek_env(c, current_word);
	else if (c->rcmd[0] != '.' && !(ft_strchr(c->rcmd, ' ')) && !c_chevron(c))
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
