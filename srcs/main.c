/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/00/00 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/00/00 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_entry	*create_entry(char *key, char *value)
{
	t_entry	*entry;

	entry = malloc(sizeof(t_entry));
	if (!entry)
	{
		free(key);
		free(value);
		return (NULL);
	}
	entry->key = key;
	entry->value = value;
	return (entry);
}

t_list	*input_list(void)
{
	char	*key;
	char	*value;
	t_list	*list;
	t_entry	*entry;

	list = NULL;
	while (1)
	{
		key = get_next_line(0);
		if (!key || key[0] == '\0')
		{
			if (key)
				free(key);
			return (list);
		}
		value = get_next_line(0);
		if (!value)
			return (free(key), list);
		entry = create_entry(key, value);
		if (!entry)
			return (list);
		ft_lstadd_back(&list, ft_lstnew(entry));
	}
	return (list);
}

void	search_data(t_hashtable *table)
{
	char	*search_key;
	char	*found_value;

	while (1)
	{
		search_key = get_next_line(0);
		if (!search_key)
			break ;
		found_value = search_value(table, search_key);
		if (found_value)
		{
			ft_putstr(found_value);
			ft_putstr("\n");
		}
		else
		{
			ft_putstr(search_key);
			ft_putstr(": Not found.\n");
		}
		free(search_key);
	}
}

int	main(void)
{
	t_hashtable	*table;
	t_list		*list;
	int			table_size;

	list = input_list();
	table_size = ft_lstsize(list);
	printf("Table size: %d\n", table_size);
	table = create_hash_table(list, table_size);
	free_list(list);
	search_data(table);
	free_hashtable(table);
	return (0);
}

// __attribute__((destructor))
// void cleanup(void)
// {
// 	system("leaks -q hotrace");
// }
