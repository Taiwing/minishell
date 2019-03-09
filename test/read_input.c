#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../src/libft/includes/libft.h"

int	main(int argc, char **argv, char **env)
{
	char	*input;
	int		rd;

	(void)argc;
	(void)argv;
	(void)env;
	ft_printf("$> ");
	while ((rd = get_next_line(0, &input)) != -1)
	{
		if (rd)
		{
			if (*input)
				ft_printf("input is: %s\n$> ", input);
			else
				ft_printf("$> ");
			free(input);
		}
	}
	return (0);
}
