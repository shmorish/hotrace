/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/00/00 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/00/00 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

static char	*allocate_line(void)
{
	char	*line;

	line = ft_calloc(1024, sizeof(char));
	return (line);
}

static int	read_buffer(int fd, char *buffer, int *pos, int *len)
{
	*len = read(fd, buffer, 1024);
	if (*len <= 0)
		return (0);
	*pos = 0;
	return (1);
}

static int	process_line(char *buffer, char *line, int *pos, int *line_pos)
{
	if (buffer[*pos] == '\n')
	{
		(*pos)++;
		return (1);
	}
	line[(*line_pos)++] = buffer[(*pos)++];
	if (*line_pos >= 1023)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024];
	static int	pos = 0;
	static int	len = 0;
	char		*line;
	int			line_pos;

	line = allocate_line();
	if (!line)
		return (NULL);
	line_pos = 0;
	while (1)
	{
		if (pos >= len)
		{
			if (!read_buffer(fd, buffer, &pos, &len))
			{
				if (line_pos == 0)
					return (free(line), NULL);
				break ;
			}
		}
		if (process_line(buffer, line, &pos, &line_pos))
			break ;
	}
	return (line);
}
