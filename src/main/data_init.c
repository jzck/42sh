/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/10 12:12:26 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

int		data_init(void)
{
	t_data	*data;
	char	*term_name;

	data = data_singleton();
	data->env = ft_sstrdup(environ);
	data->local_var = NULL;
	set_exitstatus(0, 1);
	data->comp = NULL;
	data->opts = 0;
	exec_reset();
	data->jobc.first_job = NULL;
	data->jobc.current_id = 1;
	data->lst_func = NULL;
	data->heredoc_queue = NULL;
	if ((term_name = ft_getenv(data->env, "TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	return (0);
}
