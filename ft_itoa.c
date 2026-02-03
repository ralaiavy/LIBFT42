static int	num_len(int n)
{
	int	len = (n <= 0);

	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	int		len;

	nb = n;
	len = num_len(nb);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (len-- > (n < 0))
	{
		res[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
