int	ft_countword(char const *s, char c)
{
	int			i;
	int			w;
	int			ini;

	i = 0;
	ini = -1;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && ini == -1)
		{
			ini = i;
		}
		if ((s[i + 1] == c && ini != -1) || (s[i + 1] == '\0' && ini != -1))
		{
			ini = -1;
			w++;
		}
		i++;
	}
	return (w);
}
