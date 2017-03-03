/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_getoutput.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:01:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 16:45:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define BUF_SIZE	1024

char	*command_getoutput(char *command)
{
	return (command);
	/* int			fds[2]; */
	/* t_btree		*ast; */
	/* t_astnode	item; */
	/* char		*output; */
	/* char		buf[BUF_SIZE + 1]; */
	/* int			ret; */
	/* t_exec		*exec; */

	/* output = NULL; */
	/* exec = &data_singleton()->exec; */
	/* item.type = TK_SUBSHELL; */
	/* item.data.sstr = malloc(4 * sizeof(char *)); */
	/* item.data.sstr[0] = ft_strdup(data_singleton()->argv[0]); */
	/* item.data.sstr[1] = ft_strdup("-c"); */
	/* item.data.sstr[2] = ft_strdup(command); */
	/* item.data.sstr[3] = NULL; */
	/* ast = btree_create_node(&item, sizeof(item)); */
	/* pipe(fds); */
	/* exec->process.fdout = fds[PIPE_WRITE]; */
	/* exec_command(&ast); */
	/* exec->process.fdout = STDOUT; */
	/* close(fds[PIPE_WRITE]); */
	/* while ((ret = read(fds[PIPE_READ], buf, BUF_SIZE))) */
	/* { */
	/* 	buf[ret] = 0; */
	/* 	ft_strappend(&output, buf); */
	/* } */
	/* close(fds[PIPE_READ]); */
	/* return (output); */
}
