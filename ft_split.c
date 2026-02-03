static int	count_words(char const *s, char c)
{
	int	count = 0;
	int	i = 0;

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

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i = 0;
	int		start;
	int		word;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
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
				return (free_all(tab, i - 1), NULL);
			i++;
			s += start;
		}
	}
	tab[i] = NULL;
	return (tab);
}
