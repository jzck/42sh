/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_match.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:27:14 by alao              #+#    #+#             */
/*   Updated: 2017/03/20 14:41:04 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Failsafe by checking if the nearby char are not a < or > for aggregation.
*/

static int	c_chevron(t_comp *c)
{
	size_t	pos;

	pos = c->ircmd;
	if (pos >= ft_strlen(c->rcmd))
		pos = ft_strlen(c->rcmd) - (ft_strlen(data_singleton()->line.input)
																		- pos);
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
** Seek the current word.
*/

static char	*c_current_words(t_comp *c)
{
	size_t	pos;

	pos = c->ircmd;
	if (pos >= ft_strlen(c->rcmd))
		pos = ft_strlen(c->rcmd) -
					(ft_strlen(data_singleton()->line.input) - pos + 1);
	while (pos && c->rcmd[pos] != ' ')
		--pos;
	if (c->rcmd[pos] == ' ')
		++pos;
	return (c->rcmd + pos);
}

/*
** Start the parsing for the autocompletion.
*/

int			c_matching(t_data *s, t_comp *c)
{
	char	*current_word;

	current_word = c_current_words(c);
	DG("current_word = %s", current_word);
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
