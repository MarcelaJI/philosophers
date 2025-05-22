/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:25:09 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/22 08:16:56 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	assign_forks(t_philo *philo, int index, t_sim *sim)
{
	philo->l_fork = &sim->forks[index];
	philo->r_fork = &sim->forks[(index + 1) % sim->num_of_philos];
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	taken_forks(t_philo *philo)
{
	if (philo_has_died(philo))
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork", CYAN);
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork", CYAN);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork", CYAN);
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork", CYAN);
	}
}
