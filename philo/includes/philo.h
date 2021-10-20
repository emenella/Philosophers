#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

 typedef	struct	s_arg
{
	int				total;
	int				die;
	int				eat;
	int				sleep;
	int				m_eat;
	long int		start_time;
	pthread_mutex_t	write_mutex;
	int				nb_philo_finish;
	int				stop;
}	t_arg;

typedef	struct	s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_t		thread_death_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	left_fork;
	t_arg			*p_arg;
	long int		ms_eat;
	unsigned int	nb_eat;
	int				finish;
}	t_philo;

typedef	struct	s_p
{
	t_philo	*philo;
	t_arg	arg;
}t_p;

void	ft_usleep(long int time_in_ms);
int		ft_atoi(const char *nptr);
int		parse_arg(t_p *p, int argc, char **arg);
int		init_philo(t_p *p);

#endif