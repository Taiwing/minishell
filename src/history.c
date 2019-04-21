/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 14:47:30 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/21 19:53:25 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ms_data.h"

void	load_history(t_ms_history *hist, char *home_path)
{
	int		fd;
	char	*path;
	ssize_t	cmd_len;

	fd = -1;
	hist->size = 0;
	if ((path = home_path ? ft_strjoin(home_path, "/.minihistory") : NULL)
		&& (fd = open(path, O_RDONLY)) != -1)
	{
		while (read(fd, &cmd_len, sizeof(ssize_t)) == sizeof(ssize_t)
				&& hist->size < (HISTMAX / 2))
		{
			hist->cmd[hist->size] = ft_strnew(cmd_len);
			if (read(fd, hist->cmd[hist->size++], cmd_len) != cmd_len)
			{
				ft_memdel((void **)&hist->cmd[--hist->size]);
				break ;
			}
		}
	}
	if (fd != -1)
		close(fd);
	ft_memdel((void **)&path);	
}

void	add_to_history(char *input, t_ms_history *hist, char *home_path)
{
	if (hist->size == HISTMAX)
		flush_history(hist, HISTMAX / 2, home_path);
	hist->cmd[hist->size++] = ft_strdup(input);
}


void	del_history(t_ms_history *hist, size_t start, size_t len)
{
	char	*to_del[HISTMAX];

	if (!hist || !hist->size || start + len > hist->size)
		return ;
	ft_memcpy((void *)to_del, (void *)(hist->cmd + start),
		len * sizeof(char *));
	ft_memcpy((void *)(hist->cmd + start), (void *)(hist->cmd + len),
		(hist->size - start - len) * sizeof(char *));
	hist->size -= len;
	while (len)
		ft_memdel((void **)&to_del[--len]);
}

void	write_history(int fd, t_ms_history *hist, size_t start, size_t len)
{
	size_t	i;
	ssize_t	cmd_len;

	if (!hist || !hist->size || start + len > hist->size)
		return ;
	i = 0;
	while (i < len)
	{
		cmd_len = ft_strlen(hist->cmd[start + i]);
		write(fd, &cmd_len, sizeof(ssize_t));
		write(fd, hist->cmd[start + i], cmd_len);
		++i;
	}
	del_history(hist, start, len);
}

void	flush_history(t_ms_history *hist, size_t len, char *home_path)
{
	int				fd;
	size_t			max;
	t_ms_history	old;
	char			*path;

	fd = -1;
	old.size = 0;
	if ((max = len < (HISTMAX / 2) ? (HISTMAX / 2) - len : 0))
		load_history(&old, home_path);
	if (old.size > max)
		del_history(&old, 0, old.size - max);
	if ((path = home_path ? ft_strjoin(home_path, "/.minihistory") : NULL)
		&& (fd = open(path, O_TRUNC | O_WRONLY)) != -1)
	{
		write_history(fd, &old, 0, old.size);
		write_history(fd, hist, 0, len);
	}
	else
	{
		del_history(&old, 0, old.size);
		del_history(hist, 0, len);
	}
	ft_memdel((void **)&path);
	if (fd != -1)
		close(fd);
}

