/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_match_glob.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:20:01 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 11:20:10 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Recreate the command from the globbing module responds.
*/

static void			c_replace_globbing(char **glob, size_t start)
{
	char			*ref_next;
	char			*ref_mid;
	char			*ref_prev;
	char			*str;
	size_t			pos;

	str = data_singleton()->line.input;
	pos = data_singleton()->line.pos;
	while (str[pos] && str[pos] != ' ')
		++pos;
	while (str[pos] && str[pos] == ' ')
		++pos;
	ref_prev = ft_strndup(str, start);
	ref_mid = ft_sstrtostr(glob, " ");
	ref_next = ft_strdup(str + pos);
	data_singleton()->line.input = ft_str3join(ref_prev, ref_mid, ref_next);
	free(ref_prev);
	free(ref_mid);
	free(ref_next);
	free(str);
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
** Match for globbing feature.
*/

int					c_glob_matching(void)
{
	char			*current_word;
	char			**ss_glob;
	unsigned char	*glob_echap;
	char			*str;
	size_t			pos;

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
	free(current_word);
	if (!*ss_glob || !**ss_glob ||
			!ft_strncmp(str + pos, *ss_glob, ft_strlen(*ss_glob)))
		return (0);
	c_replace_globbing(ss_glob, pos);
	return (1);
}
