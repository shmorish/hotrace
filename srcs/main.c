/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/00/00 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2025/06/29 23:16:22 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "get_next_line.h"

static int	read_key_value_pair(char **key, char **value)
{
	*key = get_next_line(0);
	if (*key == NULL || (*key)[0] == '\n')
	{
		if (*key)
			free(*key);
		return (0);
	}
	*value = get_next_line(0);
	if (!*value)
	{
		free(*key);
		return (0);
	}
	return (1);
}

static void	add_node_to_list(t_list **list, t_list **last, t_list *new_node)
{
	if (*list == NULL)
	{
		*list = new_node;
		*last = new_node;
	}
	else
	{
		(*last)->next = new_node;
		*last = new_node;
	}
}

t_list	*input_list(void)
{
	char	*key;
	char	*value;
	t_list	*list;
	t_list	*last;
	t_list	*new_node;

	list = NULL;
	last = NULL;
	while (1)
	{
		if (!read_key_value_pair(&key, &value))
			return (list);
		new_node = ft_lstnew(key, value);
		if (new_node == NULL)
			return (list);
		add_node_to_list(&list, &last, new_node);
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
		}
		else
		{
			ft_putstr_without_newline(search_key);
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
	table = create_hash_table(list, table_size);
	free_list(list);
	search_data(table);
	return (0);
}

// __attribute__((destructor))
// void cleanup(void)
// {
// 	system("leaks -q hotrace");
// }
