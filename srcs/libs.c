#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
    size_t	i;
    unsigned char	*ptr;

    ptr = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_bzero(copy, len + 1);
	while (len--)
		copy[len] = s1[len];
	return (copy);
}

void	ft_putstr(char *s)
{
	if (s)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
	}
}