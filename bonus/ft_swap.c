/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 05:57:48 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/13 19:04:10 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	sa(t_node **a)
{
	swap(a);
}

void	sb(t_node **b)
{
	swap(b);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}
