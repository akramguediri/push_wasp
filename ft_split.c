/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 05:11:48 by aguediri          #+#    #+#             */
/*   Updated: 2023/09/04 20:27:45 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_split_len(const char *s, int l, char c)
{
	int	i;

	i = 0;
	while (s[l + i] != c && s[l + i])
		i++;
	return (i);
}

static int	ft_split_start(const char *s, char c, int l)
{
	while (s[l] == c)
		l++;
	return (l);
}

void	free_split(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char *s, char c)
{
	char	**t;
	int		j;
	int		l;

	j = 0;
	l = 0;
	if (!s)
		return (NULL);
	t = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!t)
		return (NULL);
	while (s[l])
	{
		l = ft_split_start(s, c, l);
		if (ft_split_len(s, l, c) != 0)
		{
			t[j] = (char *)malloc(ft_split_len(s, l, c) * sizeof(char *));
			if (!t[j])
				free_split(t);
			ft_strlcpy(t[j], s + l, ft_split_len(s, l, c) + 1);
			t[j++][ft_split_len(s, l, c) + 1] = '\0';
		}
		l += ft_split_len(s, l, c);
	}
	return (t[j] = NULL, t);
}
