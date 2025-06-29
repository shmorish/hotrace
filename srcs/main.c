#include "hashtable.h"

int	main(void)
{
	t_hashtable	*table;
	char		*key;
	char		*value;

	table = create_hashtable(TABLE_SIZE);
	if (!table)
		return (1);
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

	while (1)
	{
		char	*search_key;
		char	*found_value;

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
			ft_putstr(search_key);
			ft_putstr(": Not found.\n");
		}
		free(search_key);
	}
	free_hashtable(table);
	return (0);
}