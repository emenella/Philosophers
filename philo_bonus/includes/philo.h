/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 03:19:01 by emenella          #+#    #+#             */
/*   Updated: 2021/10/29 03:19:58 by emenella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

typedef struct s_arg
{
	int				total;
	int				die;
	int				eat;
	int				sleep;
	int				m_eat;
	long int		start_time;
	sem_t			*write;
	sem_t			*dead;
	sem_t			*time_eat;
	sem_t			*finish;
	sem_t			*fork;
	int				nb_philo_finish;
	int				stop;
}	t_arg;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_t		thread_death_id;
	t_arg			*p_arg;
	long int		ms_eat;
	unsigned int	nb_eat;
	int				finish;
}	t_philo;

typedef struct s_p
{
	t_philo	*philo;
	t_arg	arg;
}t_p;

void		ft_usleep(long int time_in_ms);
int			ft_atoi(const char *nptr);
int			parse_arg(t_p *p, int argc, char **arg);
int			init_philo(t_p *p);
long int	actual_time(void);
int			ft_exit(char *str);
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
int			init_sem(t_p *p);
int			create_thread(t_p *p);
int			check_death2(t_p *p);
int			check_arg(int argc, char **arg);
#endif