/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_find_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:50:24 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/23 19:07:56 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Create a new list node and add it by calling c_add_to_lst.
*/

static int	c_addnode(t_comp *c, char *value)
{
	t_clst	*tmp;

	if (!(tmp = (t_clst *)ft_malloc(sizeof(t_clst))))
		return (-1);
	tmp->name = value;
	tmp->len = ft_strlen(tmp->name);
	tmp->type = 10;
	tmp->cursor = 0;
	c_add_to_lst(c, tmp);
	return (0);
}

/*
** Search in the env for matching element and add them to the list if matched.
*/

int			c_seek_env(t_comp *c, char *current_word)
{
	char	**env;
	int		i;
	int		m_len;

	i = 0;
	env = data_singleton()->env;
	c->match = ft_strdupi_w(current_word + 1);
	m_len = ft_strlen(c->match);
	while (env[i])
	{
		if (!ft_strncmp(c->match, env[i], m_len) && env[i][m_len] != '=')
			c_addnode(c, ft_strndup(env[i], ft_strchr(env[i], '=') - env[i]));
		++i;
	}
	c_lst_id(data_singleton()->comp);
	return (0);
}
