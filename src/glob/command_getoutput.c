/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_getoutput.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:01:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/13 22:25:13 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define BUF_SIZE	1024

/*static char		*manage_output(int *fds)
  {
  int			ret;
  char		buf[BUF_SIZE + 1];
  char		*output;

  output = NULL;
  while ((ret = read(fds[PIPE_READ], buf, BUF_SIZE)) > 0)
  {
  buf[ret] = 0;
  ft_strappend(&output, buf);
  }
  close(fds[PIPE_READ]);
  return (output);
  }
  */


static t_btree		*gen_t_btree(const char *command)
{
	t_btree			*ast;
	t_astnode		item;
	int				len;
	unsigned char	*esc;

	ft_bzero(&item, sizeof(t_astnode));
	item.type = SUBSHELL;
	ast = btree_create_node(&item, sizeof(t_astnode));
	ft_bzero(&item, sizeof(t_astnode));
	item.type = CMD;
	len = ft_strlen(command);
	esc = ft_memalloc((len >> 3) + 1);
	ft_ld_pushfront(&item.data.cmd.token, gen_tab(command, esc, esc, 1));
	ast->right = btree_create_node(&item, sizeof(t_astnode));
	return (ast);
}

char			*command_getoutput(char *command)
{
	t_btree		*ast;
	char		*output;
	char		buf[BUF_SIZE + 1];
	t_exec		*exec;
	t_process	p;
	int			ret;
	int			pid;

	return (NULL);
	output = NULL;
	exec = &data_singleton()->exec;
	DG("%p exec ?", exec);
	DG("\033[38;5;46mbefore");
	ast = gen_t_btree(command);
	DG();
	if (process_set(&p, ast))
		return (NULL);
	DG();
	if (!(pid = plaunch_subshell(&p)))
		return (NULL);
	waitpid(pid, &ret, WUNTRACED);
	DG();
//	exec_leaf(&ast);
	/*
	DG();
	set_process(&p, ast);
	DG();
	launch_process(&p);
	DG();
	close(p.fdout);*/
	DG();
	while ((ret = read(exec->fdin, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = 0;
		ft_strappend(&output, buf);
	}
	DG();
	close(exec->fdin);
	DG("done with %s\033[0m", output);

	return (output);
}
