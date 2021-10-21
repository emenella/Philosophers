#include "philo.h"

int	parse_arg(t_p *p, int argc, char **arg)
{
	if ((argc == 5 || argc == 6) && check_arg(arg, argc))
	{
		p->arg.total = ft_atoi(arg[1]);
		p->arg.die = ft_atoi(arg[2]);
		p->arg.eat = ft_atoi(arg[3]);
		p->arg.sleep = ft_atoi(arg[4]);
		p->arg.stop = 0;
		p->arg.nb_philo_finish = 0;
		if (argc == 6)
			p->arg.m_eat = ft_atoi(arg[5]);
		if (p->arg.total <= 0 || p->arg.die <= 0 || p->arg.eat <= 0 \
			|| p->arg.sleep <= 0)
			return (0);
		return (1);
	}
	printf("Error: bad arguments\n");
	return (0);
}

int	init_philo(t_p *p)
{
	int i;

	p->arg.start_time = actual_time();
	p->philo = malloc(sizeof(t_philo) * p->arg.total);
	if (p->philo == NULL)
		return (0);
	i = -1;
	while (++i < p->arg.total)
	{
		p->philo[i].id = i + 1;
		p->philo[i].ms_eat = p->arg.start_time;
		p->philo[i].nb_eat = 0;
		p->philo[i].finish = 0;
		p->philo[i].p_arg = &p->arg;
		p->philo[i].right_fork = NULL;
		pthread_mutex_init(&p->philo[i].left_fork, NULL);
		if (p->arg.total == 1)
			return (1);
		if (i == p->arg.total - 1)
			p->philo[i].right_fork = &p->philo[0].left_fork;
		else
			p->philo[i].right_fork = &p->philo[i + 1].left_fork;
	}
	return (1);
}