/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 05:58:07 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/13 19:05:27 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	r(t_node **stack)
{
	t_node	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *stack;
	*stack = (*stack)->next;
	current->next->next = NULL;
}

void	ra(t_node **a)
{
	r(a);
}

void	rb(t_node **b)
{
	r(b);
}

void	rr(t_node **a, t_node **b)
{
	r(a);
	r(b);
}
