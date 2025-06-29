#include "hashtable.h"

int main(void) {
    t_hashtable *table;

    table = create_hashtable(TABLE_SIZE);
    if (!table) {
        return 1;
    }

    while (1) {
        char *key, *value;
        key = get_next_line(0);
        
        if (!key || *key == '\0') {
            if (key) free(key);
            break;
        }
        
        value = get_next_line(0);
        if (!value) {
            free(key);
            break;
        }

        insert_entry(table, key, value);
        free(key);
        free(value);
    }

    while (1) {
        char *search_key = get_next_line(0);
        if (!search_key) break;
        
        char *found_value = search_value(table, search_key);
        if (found_value) {
            ft_putstr(found_value);
        } else {
            ft_putstr(search_key);
            ft_putstr(": Not found.\n");
        }
        free(search_key);
    }

    free_hashtable(table);
    return (0);
}