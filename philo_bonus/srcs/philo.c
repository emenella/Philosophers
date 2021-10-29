#include "../includes/philo.h"

void philo_write(char *str, t_philo *p)
{
	long int time;

	sem_wait(p->p_arg->write);
	time = actual_time() - p->p_arg->start_time;
	if (time >= 0 && time <= 2147483647 && !check_death(p, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s\n", p->id, str);
	}
	sem_post(p->p_arg->write);
}

void philo_sleep_think(t_philo *p)
{
	philo_write("is sleeping", p);
	ft_usleep(p->p_arg->sleep);
	philo_write("is think", p);
}

void philo_eat(t_philo *p)
{
	sem_wait(p->p_arg->fork);
	philo_write("has taken a fork", p);
	if (p->p_arg->total == 1)
	{
		ft_usleep(p->p_arg->die);
		return ;
	}
	sem_wait(p->p_arg->fork);
	philo_write("has taken a fork", p);
	philo_write("is eating", p);
	p->ms_eat = actual_time();
	sem_post(p->p_arg->fork);
	sem_post(p->p_arg->fork);
	ft_usleep(p->p_arg->eat);
	p->nb_eat++;
}

void philo_routine(void *data)
{
	t_philo *p;

	p = (t_philo*) data;
	philo_eat(p);
	philo_sleep_think(p);
}

int	check_death(t_philo *p, int i)
{
	sem_wait(p->p_arg->dead);
	if (i)
		p->p_arg->stop = i;
	if (p->p_arg->stop)
	{
		sem_post(p->p_arg->dead);
		return (1);
	}
	sem_post(p->p_arg->dead);
	return (0);
}