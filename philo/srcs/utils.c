#include "philo.h"

int	ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

void	spacejump(int *i, const char *nptr, int *j)
{
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == 32)
		*i += 1;
	*j = *i;
}

void	signjump(int *i, const char *nptr, int *minuscount)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*minuscount = 1;
		*i += 1;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	minuscount;
	int	result;

	i = 0;
	minuscount = 0;
	result = 0;
	spacejump(&i, nptr, &j);
	signjump(&i, nptr, &minuscount);
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i++] - 48;
	}
	if (minuscount == 1)
		result = -result;
	return (result);
}