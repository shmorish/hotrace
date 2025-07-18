/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hash_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:15:34 by aenshin           #+#    #+#             */
/*   Updated: 2025/06/29 23:35:02 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "get_next_line.h"

t_hashtable	*create_hash_table(t_list *l, int size)
{
	t_hashtable	*t;

	t = ft_calloc(sizeof(t_hashtable), 1);
	t->size = size * 2;
	t->count = 0;
	t->entries = ft_calloc(size * 2 * sizeof(t_entry), 1);
	while (l != NULL)
	{
		insert_entry(t, l->key, l->value);
		l = l->next;
	}
	return (t);
}

/*
void	print_list(t_list *l)
{
	while (l != NULL)
	{
		printf("key [%s] -> val [%s]\n", l->key, l->value);
		l = l->next;
	}
}
*/
