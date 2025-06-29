/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:38:53 by aenshin           #+#    #+#             */
/*   Updated: 2023/11/19 23:08:51 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

// frees first arg!
// strncat: concatenate two strings - past buf and current one with bound
// bound is in current one, up to N bytes, until newline
// if past one is NULL it is okay, allocate more
// deallocate if not NULL old one
char	*ft_strncat(char *dst, const char *src, size_t src_size)
{
	size_t	dst_size;
	size_t	i;
	char	*res;
	char	*tmp;

	if (dst == src && dst == NULL)
		return (NULL);
	dst_size = ft_strlen(dst);
	res = malloc(dst_size + src_size + 1);
	if (res == NULL)
	{
		free(dst);
		return (NULL);
	}
	tmp = res;
	ft_strcpy(tmp, dst);
	tmp = tmp + dst_size;
	i = 0;
	while (i < src_size)
		*tmp++ = src[i++];
	*tmp = '\0';
	if (dst != NULL)
		*dst = '\0';
	free(dst);
	return (res);
}

void	ft_strcpy(char	*dst, char	*src)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	while (i < src_size)
	{
		dst[i] = src[i];
		i++;
	}
	return ;
}

// locate endline
// returns pos of \n starting from 0
// i.e. number of chars before \n
ssize_t	locate_endl(char *str, size_t len)
{
	size_t	i;

	i = 0;
	if (str == NULL || len == 0)
		return (-1);
	while (i < len && str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		res++;
		s++;
	}
	return (res);
}
