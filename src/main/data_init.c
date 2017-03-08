/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 23:40:20 by ariard           ###   ########.fr       */
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
	set_exitstatus(0, 1);
	data->comp = NULL;
	data->opts = 0;
	exec_reset();

	data->jobc.first_job = NULL;
	data->jobc.current_id = 1;

	data->local_var = NULL;
	data->lst_func = NULL;
	data->heredoc_queue = NULL;
	if ((term_name = ft_getenv(data->env, "TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	return (0);
}
