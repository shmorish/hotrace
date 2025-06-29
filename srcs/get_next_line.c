/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:55:53 by aenshin           #+#    #+#             */
/*   Updated: 2023/11/19 23:23:22 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./get_next_line.h"

//probably would be good to free mem and assign NULL to it when res is NULL
//but next time : )
char	*get_next_line(int fd)
{
	static char	*mem;
	char		*res;
	char		*tmp;
	ssize_t		endl;

	endl = locate_endl(mem, ft_strlen(mem));
	if (endl >= 0)
	{
		res = ft_strncat(NULL, mem, endl + 1);
		tmp = mem;
		mem = ft_strncat(NULL, mem + endl + 1, ft_strlen(mem) - endl - 1);
		free(tmp);
		return (res);
	}
	else
	{
		if (safe_call(mem, &res) == -1)
			return (NULL);
		mem = NULL;
	}
	return (read_fd(fd, res, &mem));
}

int	safe_call(char *mem, char **res)
{
	if (mem == NULL)
		*res = NULL;
	else
	{
		*res = ft_strncat(mem, NULL, 0);
		if (res == NULL)
			return (-1);
	}
	return (1);
}

char	*read_fd(int fd, char *res, char **mem)
{
	char				*buf;
	ssize_t				cnt;
	ssize_t				endl;

	buf = malloc(BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	cnt = read(fd, buf, BUFFER_SIZE);
	while (cnt > 0)
	{
		endl = locate_endl(buf, cnt);
		if (endl >= 0)
		{
			res = ft_strncat(res, buf, endl + 1);
			*mem = ft_strncat(NULL, buf + endl + 1, cnt - endl - 1);
			free(buf);
			return (res);
		}
		else
			res = ft_strncat(res, buf, cnt);
		if (res == NULL)
			return (NULL);
		cnt = read(fd, buf, BUFFER_SIZE);
	}
	return (due_norm(buf, cnt, res));
}

char	*due_norm(char	*buf, ssize_t	cnt, char	*res)
{
	free(buf);
	if (cnt != ERR_CODE && ft_strlen(res) > 0)
		return (res);
	free(res);
	return (NULL);
}
