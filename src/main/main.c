#include "minishell.h"
extern char **environ;

int		main(void)
{
	t_data	data;

	data.env = ft_sstrdup(environ);
	data.history = ft_dlst_new(NULL, 0);
	ft_tc_init(&data);
	while (1)
	{
		ft_putstr(SHELL_PROMPT);
		if (ft_interactive_sh(&data))
			return (1);
		ft_printf("got string:'%s'\n", data.history->prev->content);
		/* return (0); */
		/* argv = ft_cmd_getav(input); */
		/* if (argv && argv[0]) */
		/* 	ft_cmd_process(argv, &data.env); */
	}
	return (0);
}

