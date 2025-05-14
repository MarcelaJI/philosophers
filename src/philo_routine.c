/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:02:12 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/14 08:41:09 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *philo_routine(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;

	wait_all_threads(philo->sim);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (should_continue(philo))
	{
		if (philo_has_died(philo))
			break;
		philo_think(philo);
		if (philo_has_died(philo))
			break;
		take_forks(philo);
		if (philo_has_died(philo))
		{
			release_forks(philo);
			break;
		}
		philo_eat(philo);
		release_forks(philo);
		if (philo_has_died(philo))
			break;
		philo_sleep(philo);
	}
	return (NULL);
}



void    take_forks(t_philo *philo)
{
	if (philo_has_died(philo))
		return;

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


void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = true;
	philo->last_meal = get_elapsed_ms(philo->sim);
	pthread_mutex_unlock(&philo->mutex);
	print_status(philo, "is eating 🍴", GREEN);
	usleep(philo->sim->time_to_eat * 1000);
	pthread_mutex_lock(&philo->mutex);
	philo->meals_eaten++;
	philo->is_eating = false;
	pthread_mutex_unlock(&philo->mutex);
}


void        philo_sleep(t_philo *philo)
{
    print_status(philo, "is sleeping 😴", BLUE);
    if (philo_has_died(philo))
        return ;
    usleep(philo->sim->time_to_sleep * 1000);
}

// No necesita dormir (el pensar es inmediato en el ciclo)
void        philo_think(t_philo *philo)
{
    if (philo_has_died(philo))
        return ;
    print_status(philo, "is thinking 🤔", MAGENTA);
}
