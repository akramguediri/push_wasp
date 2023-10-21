/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:07:48 by aguediri          #+#    #+#             */
/*   Updated: 2023/09/29 15:50:52 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorter5(t_node **a, t_node **b)
{
	if ((*a)->next->next->data == ft_stack_max(*a))
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next->data == ft_stack_max(*a))
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->next->next->next->next->data == ft_stack_max(*a))
		rra(a);
	else if ((*a)->next->data == ft_stack_max(*a))
	{
		sa(a);
	}
	pb(a, b);
	if (!ft_issorted(*a))
		sorter4(a, b);
	pa(a, b);
	ra(a);
}

void	sorter4(t_node **a, t_node **b)
{
	if ((*a)->next->next->data == ft_stack_max(*a))
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next->data == ft_stack_max(*a))
		rra(a);
	else if ((*a)->next->data == ft_stack_max(*a))
		sa(a);
	pb(a, b);
	if (!ft_issorted(*a))
		sorter3(a);
	pa(a, b);
	ra(a);
}

void	sorter3(t_node **a)
{
	if ((*a)->index > (*a)->next->index
		&& (*a)->index > (*a)->next->next->index)
	{
		ra(a);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else if ((*a)->index < (*a)->next->index
		&& (*a)->index > (*a)->next->next->index)
		rra(a);
	else if ((*a)->index > (*a)->next->index
		&& (*a)->index < (*a)->next->next->index)
		sa(a);
	else if ((*a)->index < (*a)->next->index
		&& (*a)->index < (*a)->next->next->index)
	{
		rra(a);
		sa(a);
	}
}
