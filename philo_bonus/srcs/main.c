#include "../includes/philo.h"

void	stop(t_p *p)
{
	int	i;

	i = -1;
	while (!check_death2(p))
		ft_usleep(1);
	sem_close(p->arg.fork);
	sem_close(p->arg.write);
	sem_close(p->arg.dead);
	sem_close(p->arg.time_eat);
	sem_close(p->arg.finish);
	while (++i < p->arg.total)
		pthread_join(p->philo[i].thread_id, NULL);
	if (p->arg.stop == 2)
		printf("Each philosopher ate %d time(s)\n", p->arg.m_eat);
	free(p->philo);
}

int	init_sem(t_p *p)
{
	sem_unlink("fork");
	sem_unlink("write");
	sem_unlink("dead");
	sem_unlink("finish");
	sem_unlink("time_eat");
	p->arg.fork = sem_open("fork", O_CREAT, S_IRWXU, p->arg.total);
	p->arg.write = sem_open("write", O_CREAT, S_IRWXU, 1);
	p->arg.dead = sem_open("dead", O_CREAT, S_IRWXU, 1);
	p->arg.finish = sem_open("finish", O_CREAT, S_IRWXU, 1);
	p->arg.time_eat = sem_open("time_eat", O_CREAT, S_IRWXU, 1);
	if (p->arg.fork <= 0 || p->arg.write <= 0 || p->arg.dead <= 0 || p->arg.finish <= 0 || p->arg.eat <= 0)
		return (ft_exit("Error init semphore"));
	return (0);
}

int	main(int argc, char **arg)
{
	t_p	p;

	if (parse_arg(&p, argc, arg) && init_philo(&p))
	{
		init_sem(&p);
		if (!create_thread(&p))
		{
			free(p.philo);
			return (0);
		}
		stop(&p);
	}
	return(0);
}
