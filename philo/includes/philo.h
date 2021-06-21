#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_arg
{
	int	number_philo;
	int	time_to_died;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;

}		t_arg;

void	init_arg(t_arg *arg_philo, int argc, char **arg);
int		ft_atoi(const char *nptr);
#endif