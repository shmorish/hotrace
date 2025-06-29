/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/00/00 00:00:00 by shmorish          #+#    #+#             */
/*   Updated: 2000/00/00 00:00:00 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_list	*ft_lstnew(char *key, char *value)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	ret->key = key;
	ret->value = value;
	ret->next = NULL;
	return (ret);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ret;

	ret = lst;
	if (ret == NULL)
		return (NULL);
	while (ret->next != NULL)
		ret = ret->next;
	return (ret);
}

int	ft_lstsize(t_list *lst)
{
	int		ret;
	t_list	*tmp;

	ret = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}
