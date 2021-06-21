#include "philo.h"

void	init_arg(t_arg *arg_philo, int argc, char **arg)
{
	if (argc == 5)
	{
		arg_philo->number_philo = ft_atoi(arg[1]);
		arg_philo->time_to_died = ft_atoi(arg[2]);
		arg_philo->time_to_eat = ft_atoi(arg[3]);
		arg_philo->time_to_sleep = ft_atoi(arg[4]);
	}
	else if (argc == 6)
	{
		arg_philo->number_philo = ft_atoi(arg[1]);
		arg_philo->time_to_died = ft_atoi(arg[2]);
		arg_philo->time_to_eat = ft_atoi(arg[3]);
		arg_philo->time_to_sleep = ft_atoi(arg[4]);
		arg_philo->number_of_times_each_philosopher_must_eat = ft_atoi(arg[4]);
	}
}
