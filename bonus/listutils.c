/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:20:13 by aguediri          #+#    #+#             */
/*   Updated: 2023/09/25 15:34:49 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	freelist(t_node *head)
{
	t_node	*current;
	t_node	*temp;

	current = head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

t_node	*ft_pop(t_node **head)
{
	t_node	*node;

	node = *head;
	if (node == NULL)
		return (NULL);
	*head = node->next;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(char *v, t_node **head)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return ;
	n->data = ft_atoi(v);
	n->next = *head;
	*head = n;
}

int	ft_issorted(t_node *n)
{
	t_node	*tmp;

	tmp = n;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	indexer(t_node **numbers)
{
	t_node	*current;
	t_node	*temp;
	int		i;

	i = 0;
	current = *numbers;
	while (current != NULL)
	{
		temp = *numbers;
		current->index = 0;
		while (temp != NULL)
		{
			if (temp->data < current->data)
				current->index++;
			temp = temp->next;
		}
		current = current->next;
		i++;
	}
	return (i);
}
