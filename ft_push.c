/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 05:57:34 by aguediri          #+#    #+#             */
/*   Updated: 2023/09/18 18:49:03 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstadd(int m, int b, t_node **head)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return ;
	n->data = m;
	n->index = b;
	n->next = *head;
	*head = n;
}

void	push(t_node **a, t_node **b)
{
	t_node	*t;

	t = ft_pop(a);
	ft_lstadd(t->data, t->index, b);
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
