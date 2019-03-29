#include "ms_data.h"

int		main(int argc, char **argv, char **env)
{
	t_ms_data	msd;

	(void)argc;
	(void)argv;
	ms_init(&msd, env);
	while (1)
	{
		ms_input(&msd);
		//TEMP
		if (msd.input_buffer)
		{
			if (!ft_strcmp(msd.input_buffer, "exit"))
			{
				ft_atexit(NULL);
				ft_heap_collector(NULL, FT_COLLEC_FREE);
				break ;
			}
			free(ft_heap_collector(msd.input_buffer, FT_COLLEC_GET));
			msd.input_buffer = NULL;
		}
		//TEMP
/*		if (msd.input_buffer)
			ms_parse(&msd);
		if (msd.cmd_list)
			ms_execute(&msd);*/
	}
	return (0);
}
