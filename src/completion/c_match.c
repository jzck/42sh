/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_match.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:27:14 by alao              #+#    #+#             */
/*   Updated: 2017/03/22 16:02:25 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	c_is_delim(char c)
{
	if (c == ' ' || c == '<' || c == '>' || c == '\n' || c == ';')
		return (1);
	return (0);
}

static char	*c_strdupi(char *s, int (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && !(*f)(s[i]))
		i++;
	str = (char *)ft_malloc(sizeof(char) * (i + 1));
	if (str)
	{
		str[i--] = '\0';
		while (i >= 0)
		{
			str[i] = s[i];
			i--;
		}
	}
	return (str);
}


/*
** Seek the current word.
*/

static char	*c_current_words(void)
{
	size_t	pos;
	char	*str;

	pos = data_singleton()->line.pos;
	str = data_singleton()->line.input;
	if (pos && c_is_delim(str[pos]))
		--pos;
	while (pos && !c_is_delim(str[pos]))
		--pos;
	if (c_is_delim(str[pos]))
		++pos;
	return (c_strdupi(str + pos, &c_is_delim));
}

/*
** Start the parsing for the autocompletion.
*/

int			c_matching(t_data *s, t_comp *c)
{
	char	*current_word;

	current_word = c_current_words();
	if (ft_strchr(current_word, '/'))
		c_seek_abs_path(c, current_word);
	else if (ft_strchr(current_word, '$'))
		c_seek_env(c, current_word);
	else if (current_word[0] != '.' && !(ft_strchr(c->rcmd, ' ')))
		c_seek_binary(s, c);
	else
		c_seek_files(s, c, current_word);
	ft_strdel(&current_word);
	if (s->comp && s->comp->lst)
	{
		c_sizing(c);
		return (1);
	}
	return (0);
}
