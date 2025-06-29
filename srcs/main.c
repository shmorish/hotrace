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

void	input_data(t_hashtable *table)
{
	char	*key;
	char	*value;

	while (1)
	{
		key = get_next_line(0);
		if (!key || *key == '\0')
		{
			if (key)
				free(key);
			break ;
		}
		value = get_next_line(0);
		if (!value)
		{
			free(key);
			break ;
		}
		insert_entry(table, key, value);
		free(key);
		free(value);
	}
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
			ft_putstr(found_value);
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

	table = create_hashtable(TABLE_SIZE);
	if (!table)
		return (1);
	input_data(table);
	search_data(table);
	free_hashtable(table);
	return (0);
}
