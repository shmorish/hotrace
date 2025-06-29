/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/00/00 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2025/06/29 21:13:38 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TABLE_SIZE 1024

typedef struct s_list	t_list;
typedef struct s_list
{
	char	*key;
	char	*value;
	t_list	*next;
}			t_list;

typedef struct s_entry
{
	char	*key;
	char	*value;
}	t_entry;

typedef struct s_hashtable
{
	t_entry	*entries;
	size_t	size;
	size_t	count;
}	t_hashtable;

// t_hashtable		*create_hashtable(size_t size);
unsigned int	hash_function(const char *key, size_t table_size);
int				insert_entry(t_hashtable *table, char *key, char *value);
char			*search_value(t_hashtable *table, char *key);
void			free_hashtable(t_hashtable *table);
char			*get_next_line(int fd);
void			input_data(t_hashtable *table);
void			search_data(t_hashtable *table);

// libs
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s1);
void			ft_putstr(char *s);
void			ft_putstr_without_newline(char *s);

// list utils
t_list			*ft_lstnew(char *key, char *value);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			free_list(t_list *list);
void			print_list(t_list *l);
t_hashtable		*create_hash_table(t_list *l, int size);

#endif
