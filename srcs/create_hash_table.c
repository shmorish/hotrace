/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hash_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenshin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:15:34 by aenshin           #+#    #+#             */
/*   Updated: 2025/06/29 21:16:42 by aenshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "get_next_line.h"

t_hashtable	*create_hash_table(t_list *l, int size)
{
	t_hashtable	*t;
	t_entry		*e;

	t = malloc(sizeof(t_hashtable));
	t->size = size;
	t->count = 0;
	t->entries = malloc(size * 2 * sizeof(t_entry));
	while (l != NULL)
	{
		e = l->content;
		insert_entry(t, e->key, e->value);
	}
	return (t);
}

/*
void	print_list(t_list *l)
{
	t_entry	*e;

	while (l != NULL)
	{
		e = l->content;
		printf("key [%s] -> val [%s]\n", e->key, e->value);
		l = l->next;
	}
}
*/
