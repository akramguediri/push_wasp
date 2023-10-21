/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:39:48 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/13 19:10:13 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_number(char *input)
{
	if (*input == '\0')
		return (0);
	if (*input == '+' || *input == '-')
		input++;
	while (*input != '\0')
	{
		if (*input < '0' || *input > '9')
			return (0);
		input++;
	}
	return (1);
}

int	isstrint(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && (str[i] >= '0' || str[i] <= '9'))
		{
			n = 1;
			break ;
		}
		i++;
	}
	return (n);
}

int	checkdups(t_node *numbers)
{
	t_node	*current;
	t_node	*temp;

	current = numbers;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (temp->data == current->data)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
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
