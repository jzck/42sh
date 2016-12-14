#include "job_control.h"

t_process	*job_getprocess(pid_t pid)
{
	t_jobc		*jobc;
	t_job		*j;
	t_list		*lst;
	t_list		*jlist;

	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	while (jlist)
	{
		j = jlist->content;
		if ((lst = ft_lst_find(j->first_process, &pid, &process_cmp_pid)))
			return (lst->content);
		jlist = jlist->next;
	}
	return (NULL);
}
