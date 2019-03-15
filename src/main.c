#include "ms_data.h"

int	main(int argc, char **argv, char **env)
{
	t_ms_data	msd;

	ms_init(&msd, env);
	while (1)
	{
		ms_input(&msd);
		if (msd.input_buffer)
			ms_parse(&msd);
		if (msd.cmd_list)
			ms_execute(&msd);
	}
	return (0);
}
