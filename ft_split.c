/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fralaiav <fralaiav@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:03:24 by fralaiav          #+#    #+#             */
/*   Updated: 2026/02/10 16:11:05 by fralaiav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	free_all(char **tab, int i)
{
	while (i >= 0)
		free(tab[i--]);
	free(tab);
}

static int	str_sub(char const *s, char **tab, char c)
{
	int	i;
	int	start;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			start = 0;
			while (s[start] && s[start] != c)
				start++;
			tab[i] = ft_substr(s, 0, start);
			if (!tab[i])
			{
				free_all(tab, i - 1);
				return (-1);
			}
			i++;
			s += start;
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	int			last_index;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	last_index = str_sub(s, tab, c);
	if (last_index == -1)
		return (NULL);
	tab[last_index] = NULL;
	return (tab);
}
