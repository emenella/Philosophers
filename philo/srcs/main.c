/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 03:14:38 by emenella          #+#    #+#             */
/*   Updated: 2021/10/29 03:15:23 by emenella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	stop(t_p *p)
{
	int	i;

	i = -1;
	while (!check_death2(p))
		ft_usleep(1);
	while (++i < p->arg.total)
		pthread_join(p->philo[i].thread_id, NULL);
	pthread_mutex_destroy(&p->arg.write_mutex);
	i = -1;
	while (++i < p->arg.total)
		pthread_mutex_destroy(&p->philo[i].left_fork);
	if (p->arg.stop == 2)
		printf("Each philosopher ate %d time(s)\n", p->arg.m_eat);
	free(p->philo);
}

void	init_mutex(t_p *p)
{
	pthread_mutex_init(&p->arg.write_mutex, NULL);
	pthread_mutex_init(&p->arg.dead, NULL);
	pthread_mutex_init(&p->arg.time_eat, NULL);
	pthread_mutex_init(&p->arg.finish, NULL);
}

int	main(int argc, char **arg)
{
	t_p	p;

	if (parse_arg(&p, argc, arg) && init_philo(&p))
	{
		init_mutex(&p);
		if (!create_thread(&p))
		{
			free(p.philo);
			return (0);
		}
		stop(&p);
	}
	return (0);
}
