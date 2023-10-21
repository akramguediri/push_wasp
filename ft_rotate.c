/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 05:58:07 by aguediri          #+#    #+#             */
/*   Updated: 2023/09/18 18:48:51 by aguediri         ###   ########.fr       */
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
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	r(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	r(a);
	r(b);
	write(1, "rr\n", 3);
}
