/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:56:41 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/14 11:26:57 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fillb(t_node **a, t_node **b, int len)
{
	int	i;
	int	range;

	i = 0;
	range = (ft_sqrt(len) - 1) * 14 / 10;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	sortphase(t_node **stack_a, t_node **stack_b, int len)
{
	int	rb_count;
	int	rrb_count;

	while (len - 1 >= 0)
	{
		rb_count = cr((*stack_b), len - 1);
		rrb_count = (len + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*stack_b)->index != len - 1)
				rb(stack_b);
			pa(stack_a, stack_b);
			len--;
		}
		else
		{
			while ((*stack_b)->index != len - 1)
				rrb(stack_b);
			pa(stack_a, stack_b);
			len--;
		}
	}
}

void	sorter(t_node **a, t_node **b, int i)
{
	fillb(a, b, i);
	sortphase(a, b, i);
}

void	sort(t_node **a, int i)
{
	t_node	*b;

	if (i == 2)
		sa(a);
	else if (i == 3)
		sorter3(a);
	else if (i == 4)
		sorter4(a, &b);
	else if (i == 5)
		sorter5(a, &b);
	else
		sorter(a, &b, i);
}

int	ft_stack_max(t_node *a)
{
	t_node	*current;
	int		max;

	current = a;
	max = current->data;
	while (current != NULL)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}
