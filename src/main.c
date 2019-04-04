#include "ms_data.h"

int		main(int argc, char **argv, char **env)
{
	t_ms_data	msd;

	(void)argc;
	(void)argv;
	ms_init(&msd, env);
	while (1)
	{
		if (!msd.input_buffer)
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
			else
				ft_memdel((void **)&msd.input_buffer);
		}
		/*if (msd.input_buffer)
			ms_parse(&msd);
		if (msd.cmd)
			ms_execute(&msd);*/
	}
	return (0);
}
