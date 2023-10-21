/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:52:58 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/14 19:10:07 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	checkvalid(char *s)
{
	if (!ft_strncmp(s, "pa", 2) || !ft_strncmp(s, "pb", 2))
		return (1);
	else if (!ft_strncmp(s, "ra", 2) || !ft_strncmp(s, "rb", 2)
		|| !ft_strncmp(s, "rr", 2))
		return (1);
	else if (!ft_strncmp(s, "sa", 2) || !ft_strncmp(s, "sb", 2)
		|| !ft_strncmp(s, "ss", 2))
		return (1);
	else if (!ft_strncmp(s, "rra", 3) || !ft_strncmp(s, "rrb", 3)
		|| !ft_strncmp(s, "rrr", 3))
		return (1);
	else
		return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*r;

	r = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	if (r == NULL || !s1 || !s2)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		r[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	return (r);
}

int	main(int argc, char **argv)
{
	t_node	*head;
	char	line[4];
	int		c;
	char	*s;

	s = malloc(4);
	head = NULL;
	c = 2;
	while (c > 1)
	{
		c = read(0, line, 4);
		line[c] = '\0';
		if (checkvalid(line))
			s = ft_strjoin(s, line);
	}
	processargs(argc, argv, &head, s);
	free(s);
}
