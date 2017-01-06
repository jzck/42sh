#include "exec.h"

void	process_reset(void)
{
	t_data		*data;

	data = data_singleton();
	data->exec.process.path = NULL;
	data->exec.process.av = NULL;
	/* data->exec.process.fdin = STDIN; */
	/* data->exec.process.fdout = STDOUT; */
	data->exec.process.pid = 0;
	data->exec.process.attributes = PROCESS_PIPESTART | PROCESS_PIPEEND;
}
