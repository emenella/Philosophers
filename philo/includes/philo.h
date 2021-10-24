#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
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
	pthread_mutex_t	dead;
	pthread_mutex_t	time_eat;
	pthread_mutex_t	finish;
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

void		ft_usleep(long int time_in_ms);
int			ft_atoi(const char *nptr);
int			parse_arg(t_p *p, int argc, char **arg);
int			init_philo(t_p *p);
long int	actual_time(void);
int			ft_exit(char* str);
int			check_death(t_philo *p, int i);
void		philo_routine(void *data);
void		philo_eat(t_philo *p);
void		philo_sleep_think(t_philo *p);
void		philo_write(char *str, t_philo *p);
void		philo_routine(void *data);
int			check_death(t_philo *p, int i);
void		*is_dead(void	*data);
void		*thread(void *data);
void		stop(t_p *p);
void		init_mutex(t_p *p);
int			create_thread(t_p *p);
int			check_death2(t_p *p);
int			check_arg(int argc, char **arg);

#endif