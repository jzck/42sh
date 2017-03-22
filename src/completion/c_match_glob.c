/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_match_glob.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:20:01 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/22 11:52:18 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Recreate the command from the globbing module responds.
*/

static void			c_replace_globbing(char **glob, size_t start, size_t pos)
{
	char			*ref_next;
	char			*ref_mid;
	char			*ref_prev;
	char			*str;

	str = data_singleton()->line.input;
	while (str[pos] && str[pos] != ' ')
		++pos;
	while (str[pos] && str[pos] == ' ')
		++pos;
	ref_prev = ft_strndup(str, start);
	ref_mid = ft_sstrtostr(glob, " ");
	ref_next = ft_strdup(str + pos);
	data_singleton()->line.input = ft_str3join(ref_prev, ref_mid, ref_next);
	if (ft_strlen(data_singleton()->line.input) > SIZE_LINE)
	{
		ft_strdel(&data_singleton()->line.input);
		data_singleton()->line.input = str;
	}
	else
		ft_strdel(&str);
	ft_strdel(&ref_prev);
	ft_strdel(&ref_mid);
	ft_strdel(&ref_next);
	ft_sstrfree(glob);
}

/*
** 42 norme. Readjust the position.
*/

static int			c_glob_pos(char *str, size_t pos)
{
	str = data_singleton()->line.input;
	pos = data_singleton()->line.pos;
	if (!str)
		return (-1);
	if (pos && str[pos] == ' ')
		--pos;
	while (pos && str[pos] != ' ')
		--pos;
	if (str[pos] == ' ')
		++pos;
	return (pos);
}

/*
** check glob return and free
*/

static int			c_check_glob(char **ss_glob, char *current_word,
					unsigned char *glob_echap, size_t pos)
{
	char			*str;

	str = data_singleton()->line.input;
	free(current_word);
	free(glob_echap);
	if (!*ss_glob || !**ss_glob ||
	!ft_strncmp(str + pos, *ss_glob, ft_strlen(*ss_glob)))
	{
		ft_sstrfree(ss_glob);
		return (1);
	}
	return (0);
}

/*
** Match for globbing feature.
*/

int					c_glob_matching(void)
{
	char			*current_word;
	char			**ss_glob;
	unsigned char	*glob_echap;
	char			*str;
	long			pos;

	str = data_singleton()->line.input;
	if ((pos = c_glob_pos(NULL, 0)) == -1)
		return (0);
	current_word = ft_strdupi_w(str + pos);
	if (current_word[0] == '$')
	{
		free(current_word);
		return (0);
	}
	glob_echap = (unsigned char *)ft_strnew(ft_strlen(str) >> 3);
	ft_bzero(glob_echap, ft_strlen(str) >> 3);
	ss_glob = glob(current_word, glob_echap, glob_echap, 1);
	if (c_check_glob(ss_glob, current_word, glob_echap, pos))
		return (0);
	c_replace_globbing(ss_glob, pos, data_singleton()->line.pos);
	return (1);
}
