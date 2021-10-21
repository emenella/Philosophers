#include "philo.h"

void philo_write(char *str, t_philo *p)
{
	long int time;

	pthread_mutex_lock(&p->p_arg->write_mutex);
	time = actual_time() - p->p_arg->start_time;
	if (time >= 0 && time <= 2147483647 && !check_death(p, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s\n", p->id, str);
	}
	pthread_mutex_unlock(&p->p_arg->write_mutex);
}

void philo_sleep_think(t_philo *p)
{
	philo_write("is sleeping", p);
	ft_usleep(p->p_arg->sleep);
	philo_write("is think", p);
}

void philo_eat(t_philo *p)
{
	pthread_mutex_lock(&p->left_fork);
	philo_write("has taken a fork", p);
	if (!p->right_fork)
	{
		ft_usleep(p->p_arg->die * 2);
		return ;
	}
	pthread_mutex_lock(p->right_fork);
	philo_write("has taken a fork", p);
	philo_write("is eating", p);
	pthread_mutex_unlock(&p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	p->nb_eat++;
}

void philo_routine(void *data)
{
	t_philo *p;

	p = (t_philo*) data;
	while (!p->finish)
	{
		philo_eat(p);
		philo_sleep_think(p);
	}
}

int	check_death(t_philo *p, int i)
{
	pthread_mutex_lock(&p->p_arg->dead);
	if (i)
		p->p_arg->stop = i;
	if (p->p_arg->stop)
	{
		pthread_mutex_unlock(&p->p_arg->dead);
		return (1);
	}
	pthread_mutex_unlock(&p->p_arg->dead);
	return (0);
}