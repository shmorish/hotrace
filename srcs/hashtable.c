/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/00/00 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/00/00 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include <unistd.h>

// t_hashtable	*create_hashtable(size_t size)
// {
// 	t_hashtable	*table;

// 	table = malloc(sizeof(t_hashtable));
// 	if (!table)
// 		return (NULL);
// 	table->entries = ft_calloc(size, sizeof(t_entry));
// 	if (!table->entries)
// 	{
// 		free(table);
// 		return (NULL);
// 	}
// 	table->size = size;
// 	table->count = 0;
// 	return (table);
// }

unsigned int	hash_function(const char *key, size_t table_size)
{
	unsigned int	hash;
	int				c;

	hash = 5381;
	c = *key++;
	while (c)
	{
		hash = ((hash << 5) + hash) + c;
		c = *key++;
	}
	return (hash % table_size);
}

int	insert_entry(t_hashtable *table, char *key, char *value)
{
	unsigned int	index;
	unsigned int	original_index;

	if (!table || !key || !value)
		return (0);
	if (table->count >= table->size)
		return (0);
	index = hash_function(key, table->size);
	original_index = index;
	while (table->entries[index].key != NULL)
	{
		if (ft_strcmp(table->entries[index].key, key) == 0)
		{
			free(table->entries[index].value);
			table->entries[index].value = ft_strdup(value);
			return (1);
		}
		index = (index + 1) % table->size;
		if (index == original_index)
			return (0);
	}
	table->entries[index].key = ft_strdup(key);
	table->entries[index].value = ft_strdup(value);
	table->count++;
	return (1);
}

char	*search_value(t_hashtable *table, char *key)
{
	unsigned int	index;
	unsigned int	original_index;

	if (!table || !key)
		return (NULL);
	index = hash_function(key, table->size);
	original_index = index;
	while (table->entries[index].key != NULL)
	{
		if (ft_strcmp(table->entries[index].key, key) == 0)
			return (table->entries[index].value);
		index = (index + 1) % table->size;
		if (index == original_index)
			break ;
	}
	return (NULL);
}

void	free_hashtable(t_hashtable *table)
{
	size_t	i;

	if (!table)
		return ;
	i = 0;
	while (i < table->size)
	{
		if (table->entries[i].key)
		{
			free(table->entries[i].key);
			free(table->entries[i].value);
		}
		i++;
	}
	free(table->entries);
	free(table);
}
