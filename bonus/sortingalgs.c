/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:56:41 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/14 13:29:44 by aguediri         ###   ########.fr       */
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

// void	check(t_node **a, char *s)
// {
// 	t_node	*b;
// 	char	**t;
// 	int		i;

// 	t = ft_split(s, '\n');
// 	i = 0;
// 	while (t[i])
// 	{
// 		if (!ft_strncmp(t[i], "ra", 2))
// 			ra(a);
// 		else if (!ft_strncmp(t[i], "rb", 2))
// 			rb(&b);
// 		else if (!ft_strncmp(t[i], "sa", 2))
// 			sa(a);
// 		else if (!ft_strncmp(t[i], "sb", 2))
// 			sb(&b);
// 		else if (!ft_strncmp(t[i], "ss", 2))
// 			ss(a, &b);
// 		else if (!ft_strncmp(t[i], "rr", 2))
// 			rr(a, &b);
// 		else if (!ft_strncmp(t[i], "rrr", 3))
// 			rrr(a, &b);
// 		else if (!ft_strncmp(t[i], "rra", 3))
// 			rra(a);
// 		else if (!ft_strncmp(t[i], "rrb", 3))
// 			rrb(&b);
// 		else if (!ft_strncmp(t[i], "pa", 2))
// 			pa(a, &b);
// 		else if (!ft_strncmp(t[i], "pb", 2))
// 			pb(a, &b);
// 		i++;
// 	}
// 	if (ft_issorted(*a))
// 		write(1, "OK\n", 3);
// 	else
// 		write(1, "KO\n", 3);
// }
void	apply_instruction(t_node **a, t_node **b, char *instruction)
{
	if (!ft_strncmp(instruction, "ra", 2))
		ra(a);
	if (!ft_strncmp(instruction, "rb", 2))
		rb(b);
	if (!ft_strncmp(instruction, "sa", 2))
		sa(a);
	if (!ft_strncmp(instruction, "sb", 2))
		sb(b);
	if (!ft_strncmp(instruction, "ss", 2))
		ss(a, b);
	if (!ft_strncmp(instruction, "rr", 2))
		rr(a, b);
	if (!ft_strncmp(instruction, "rrr", 3))
		rrr(a, b);
	if (!ft_strncmp(instruction, "rra", 3))
		rra(a);
	if (!ft_strncmp(instruction, "rrb", 3))
		rrb(b);
	if (!ft_strncmp(instruction, "pa", 2))
		pa(a, b);
	if (!ft_strncmp(instruction, "pb", 2))
		pb(a, b);
}
// void	printLinkedList(t_node *head)
// {
// 	t_node	*current;

// 	current = head;
// 	while (current != NULL)
// 	{
// 		printf("%d -> ", current->data);
// 		current = current->next;
// 	}
// 	printf("NULL\n");
// }

void	check(t_node **a, char *s)
{
	t_node	*b;
	char	**t;
	int		i;

	t = ft_split(s, '\n');
	i = 0;
	while (t[i])
	{
		apply_instruction(a, &b, t[i]);
		i++;
	}
	if (ft_issorted(*a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
