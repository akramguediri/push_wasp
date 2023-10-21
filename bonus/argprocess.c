/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:35:10 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/13 19:00:51 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	oarg(char *str, t_node **head)
{
	int		j;
	char	**s;
	t_node	*new_node;

	j = 0;
	s = ft_split(str, ' ');
	while (s[j])
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			exit(1);
		ft_lstadd_back(s[j], head);
		j++;
	}
}

void	margs(char **str, t_node **head)
{
	t_node	*new_node;
	int		i;

	i = 1;
	while (str[i])
	{
		if (is_number(str[i]))
		{
			new_node = (t_node *)malloc(sizeof(t_node));
			if (!new_node)
				exit(1);
			ft_lstadd_back(str[i], head);
		}
		else if (isstrint(str[i]))
			oarg(str[i], head);
		else
		{
			ft_error();
			freelist(*head);
			exit(1);
		}
		i++;
	}
}

void	processargs(int argc, char **argv, t_node **head, char *s)
{
	int	i;

	if (argc <= 1)
		ft_error();
	else
	{
		if (argc == 2 && isstrint(argv[1]))
			oarg(argv[1], head);
		else
			margs(argv, head);
		if (*head)
		{
			if (ft_issorted(*head) || checkdups(*head))
				ft_error();
			else
			{
				i = indexer(head);
				check(head, s);
			}
		}
	}
	freelist(*head);
}
