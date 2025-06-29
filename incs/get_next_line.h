/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:33:33 by aenshin           #+#    #+#             */
/*   Updated: 2025/06/29 21:23:13 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE	
#  define BUFFER_SIZE	4096
# endif
# include <stddef.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define EOF_CODE 0
# define ERR_CODE -1

char	*due_norm(char	*buf, ssize_t	cnt, char	*res);
char	*read_fd(int fd, char *res, char **mem);
size_t	ft_strlen(const char *s);
ssize_t	locate_endl(char *str, size_t len);
char	*get_next_line(int fd);
char	*ft_strncat(char *dst, const char *src, size_t src_size);
void	ft_strcpy(char	*dst, char	*src);
int		safe_call(char *mem, char **res);
#endif
