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

#include "hotrace.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024];
	static int	pos = 0;
	static int	len = 0;
	char		*line;
	int			line_pos;

	line = malloc(1024);
	if (!line)
		return (NULL);
	line_pos = 0;
	while (1)
	{
		if (pos >= len)
		{
			len = read(fd, buffer, 1024);
			if (len <= 0)
			{
				if (line_pos == 0)
				{
					free(line);
					return (NULL);
				}
				break ;
			}
			pos = 0;
		}
		if (buffer[pos] == '\n')
		{
			pos++;
			break ;
		}
		line[line_pos++] = buffer[pos++];
		if (line_pos >= 1023)
			break ;
	}
	line[line_pos] = '\0';
	return (line);
}