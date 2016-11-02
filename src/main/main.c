#include "minishell.h"
extern char	**environ;
int			g_mode;

int		main(void)
{
	t_data	data;
	char	**av;

	data.env = ft_sstrdup(environ);
	data.history = ft_dlst_new(NULL, 0);
	ft_tc_init(&data);
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_printf("\ncan't catch SIGINT\n");
	while (1)
	{
		g_mode = MODE_INPUT;
		ft_prompt();
		if (ft_interactive_sh(&data))
			return (1);
		g_mode = MODE_EXEC;
		/* ft_printf("got string:'%s'\n", data.history->prev->content); */
		av = ft_cmd_getav(data.history->prev->content);
		if (av && av[0])
			ft_cmd_process(av, &data.env);
	}
	return (0);
}

