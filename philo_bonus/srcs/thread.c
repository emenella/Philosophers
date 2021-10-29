/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 03:21:18 by emenella          #+#    #+#             */
/*   Updated: 2021/10/29 03:21:32 by emenella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*thread(void *data)
{
	t_philo	*p;

	p = (t_philo *)data;
	if (p->id % 2 == 0)
		ft_usleep(p->p_arg->eat / 10);
	while (!check_death(p, 0))
	{
		pthread_create(&p->thread_death_id, NULL, is_dead, data);
		philo_routine(p);
		pthread_detach(p->thread_death_id);
		if ((int)p->nb_eat == p->p_arg->m_eat)
		{
			sem_wait(p->p_arg->finish);
			p->finish = 1;
			p->p_arg->nb_philo_finish++;
			if (p->p_arg->nb_philo_finish == p->p_arg->total)
			{
				sem_post(p->p_arg->finish);
				check_death(p, 2);
			}
			sem_post(p->p_arg->finish);
			return (NULL);
		}
	}
	return (NULL);
}

int	check_death2(t_p *p)
{
	sem_wait(p->arg.dead);
	if (p->arg.stop)
	{
		sem_post(p->arg.dead);
		return (1);
	}
	sem_post(p->arg.dead);
	return (0);
}

void	*is_dead(void	*data)
{
	t_philo	*p;

	p = (t_philo *)data;
	ft_usleep(p->p_arg->die);
	sem_wait(p->p_arg->time_eat);
	sem_wait(p->p_arg->finish);
	if (!check_death(p, 0) && !p->finish && ((actual_time() - p->ms_eat) \
		>= (long)(p->p_arg->die)))
	{
		sem_post(p->p_arg->time_eat);
		sem_post(p->p_arg->finish);
		philo_write("died", p);
		check_death(p, 1);
	}
	sem_post(p->p_arg->time_eat);
	sem_post(p->p_arg->finish);
	return (NULL);
}

int	create_thread(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->arg.total)
	{
		p->philo[i].p_arg = &p->arg;
		if (pthread_create(&p->philo[i].thread_id, NULL,
				thread, &p->philo[i]) != 0)
			return (ft_exit("Pthread did not return 0\n"));
		i++;
	}
	return (1);
}
