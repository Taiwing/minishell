#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv, char **env)
{
	ssize_t	rd;
	char	buf[256];

	(void)argc;
	(void)argv;
	(void)env;
	write(1, "$> ", 3);
	while ((rd = read(0, buf, 256)) != -1)
	{
		if (rd)
		{
			printf("command is: %.*s\n", (int)rd, buf)
			write(1, "$> ", 3);
		}
	}
	return (0);
}
