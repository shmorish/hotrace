#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TABLE_SIZE 1024
#define DELETED_MARKER ((void*)1)

typedef struct s_entry {
    char *key;
    char *value;
    int is_deleted;
} t_entry;

typedef struct s_hashtable {
    t_entry *entries;
    size_t size;
    size_t count;
} t_hashtable;

t_hashtable *create_hashtable(size_t size);
unsigned int hash_function(const char *key, size_t table_size);
int insert_entry(t_hashtable *table, char *key, char *value);
char *search_value(t_hashtable *table, char *key);
void free_hashtable(t_hashtable *table);
char *get_next_line(int fd);

// libs
void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t count, size_t size);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strdup(const char *s1);
void ft_putstr(char *s);

#endif