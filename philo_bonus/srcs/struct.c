/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emenella <emenella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 03:21:07 by emenella          #+#    #+#             */
/*   Updated: 2021/10/29 03:21:15 by emenella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parse_arg(t_p *p, int argc, char **arg)
{
	if ((argc == 5 || argc == 6) && check_arg(argc, arg))
	{
		p->arg.total = ft_atoi(arg[1]);
		p->arg.die = ft_atoi(arg[2]);
		p->arg.eat = ft_atoi(arg[3]);
		p->arg.sleep = ft_atoi(arg[4]);
		p->arg.stop = 0;
		p->arg.nb_philo_finish = 0;
		p->arg.m_eat = -1;
		if (argc == 6)
			p->arg.m_eat = ft_atoi(arg[5]);
		if (p->arg.total <= 0 || p->arg.die <= 0 || p->arg.eat <= 0 \
			|| p->arg.sleep <= 0)
			return (ft_exit("0 in arg"));
		return (1);
	}
	printf("Error: bad arguments\n");
	return (0);
}

int	init_philo(t_p *p)
{
	int	i;

	p->arg.start_time = actual_time();
	p->philo = malloc(sizeof(t_philo) * p->arg.total);
	if (p->philo == NULL)
		return (ft_exit("Error malloc of philo"));
	i = -1;
	while (++i < p->arg.total)
	{
		p->philo[i].id = i + 1;
		p->philo[i].ms_eat = p->arg.start_time;
		p->philo[i].nb_eat = 0;
		p->philo[i].finish = 0;
		p->philo[i].p_arg = &p->arg;
	}
	return (1);
}
