/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:02:12 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/16 12:32:59 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	struct timeval	current_time;

	philo = (t_philo *)arg;
	wait_all_threads(philo->sim);
	while (should_continue(philo))
	{
		take_forks(philo);
		philo_eat(philo);
		if (philo->full)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	if (philo->full && !philo->sim->dead_lock)
	{
		gettimeofday(&current_time, NULL);
		printf(RESET"%ld %d"YELLOW" is full😋, eats %d times\n"RESET, get_time_in_ms(philo->sim), 
		philo->id, philo->meals_eaten);
	}
	return (NULL);
}

void	take_forks(t_philo *philo)
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

void philo_eat(t_philo *philo)
{
	print_status(philo, "is eating 🍴", GREEN);
	pthread_mutex_lock(&philo->mutex);
	philo->meals_eaten++;
	philo->is_eating = true;
	philo->last_meal = get_time_in_ms(philo->sim);
	usleep(philo->sim->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->mutex);
	if (philo->meals_eaten
		 == philo->sim->num_times_to_eat)
		 philo->full = true;
	philo->is_eating = false;
	pthread_mutex_unlock(&philo->mutex);
}


void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping 😴", BLUE);
	if (philo_has_died(philo))
		return ;
	usleep(philo->sim->time_to_sleep * 1000);
}

// No necesita dormir (el pensar es inmediato en el ciclo)
void	philo_think(t_philo *philo)
{
	if (philo_has_died(philo))
		return ;
	print_status(philo, "is thinking 🤔", MAGENTA);
}
