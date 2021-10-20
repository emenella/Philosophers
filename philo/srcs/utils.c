void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	sum;

	sum = 0;
	i = -1;
	while (nptr[++i])
		sum = (sum * 10) + (nptr[i] - 48);
	return (sum);
}

int	check_arg(int argc, char **arg)
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (arg[i][++j])
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (0);
	}
	return (1);
}