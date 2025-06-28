#include "hashtable.h"
#include <unistd.h>

t_hashtable *create_hashtable(size_t size) {
    t_hashtable *table = malloc(sizeof(t_hashtable));
    if (!table) return NULL;
    
    table->entries = calloc(size, sizeof(t_entry));
    if (!table->entries) {
        free(table);
        return NULL;
    }
    
    table->size = size;
    table->count = 0;
    
    return table;
}

unsigned int hash_function(const char *key, size_t table_size) {
    unsigned int hash = 5381;
    int c;
    
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }
    
    return hash % table_size;
}

int insert_entry(t_hashtable *table, char *key, char *value) {
    if (!table || !key || !value || table->count >= table->size) {
        return 0;
    }
    
    unsigned int index = hash_function(key, table->size);
    unsigned int original_index = index;
    
    while (table->entries[index].key != NULL && !table->entries[index].is_deleted) {
        if (strcmp(table->entries[index].key, key) == 0) {
            free(table->entries[index].value);
            table->entries[index].value = strdup(value);
            return 1;
        }
        
        index = (index + 1) % table->size;
        
        if (index == original_index) {
            return 0;
        }
    }
    
    if (table->entries[index].is_deleted) {
        free(table->entries[index].key);
        free(table->entries[index].value);
        table->entries[index].is_deleted = 0;
    }
    
    table->entries[index].key = strdup(key);
    table->entries[index].value = strdup(value);
    table->count++;
    
    return 1;
}

char *search_value(t_hashtable *table, char *key) {
    if (!table || !key) {
        return NULL;
    }
    
    unsigned int index = hash_function(key, table->size);
    unsigned int original_index = index;
    
    while (table->entries[index].key != NULL) {
        if (!table->entries[index].is_deleted && 
            strcmp(table->entries[index].key, key) == 0) {
            return table->entries[index].value;
        }
        
        index = (index + 1) % table->size;
        
        if (index == original_index) {
            break;
        }
    }
    
    return NULL;
}

void free_hashtable(t_hashtable *table) {
    if (!table) return;
    
    for (size_t i = 0; i < table->size; i++) {
        if (table->entries[i].key && !table->entries[i].is_deleted) {
            free(table->entries[i].key);
            free(table->entries[i].value);
        }
    }
    
    free(table->entries);
    free(table);
}

char *get_next_line(int fd) {
    static char buffer[1024];
    static int pos = 0;
    static int len = 0;
    char *line = malloc(1024);
    int line_pos = 0;
    
    if (!line) return NULL;
    
    while (1) {
        if (pos >= len) {
            len = read(fd, buffer, 1024);
            if (len <= 0) {
                if (line_pos == 0) {
                    free(line);
                    return NULL;
                }
                break;
            }
            pos = 0;
        }
        
        if (buffer[pos] == '\n') {
            pos++;
            break;
        }
        
        line[line_pos++] = buffer[pos++];
        
        if (line_pos >= 1023) {
            break;
        }
    }
    
    line[line_pos] = '\0';
    return line;
}