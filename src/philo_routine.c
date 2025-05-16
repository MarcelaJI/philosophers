/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:02:12 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/16 09:36:45 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->sim);
	pthread_mutex_lock(&philo->mutex);
	printf("[DEBUG] Philo %d starts with last_meal = %ld\n", philo->id, philo->last_meal);
	pthread_mutex_unlock(&philo->mutex);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (should_continue(philo))
	{
		if (philo_has_died(philo))
			break ;
		philo_think(philo);
		if (philo_has_died(philo))
			break ;
		printf("[DEBUG] Philo %d trying to take forks at %ld ms\n",
			philo->id, get_elapsed_ms(philo->sim));
		take_forks(philo);
		printf("[DEBUG] Philo %d took forks at %ld ms\n",
			philo->id, get_elapsed_ms(philo->sim));
		if (philo_has_died(philo))
		{
			release_forks(philo);
			printf("[DEBUG] Philo %d released forks at %ld ms due to death\n",
				philo->id, get_elapsed_ms(philo->sim));
			break ;
		}
		philo_eat(philo);
		release_forks(philo);
		printf("[DEBUG] Philo %d released forks at %ld ms after eating\n",
			philo->id, get_elapsed_ms(philo->sim));
		if (philo_has_died(philo))
			break ;
		philo_sleep(philo);
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
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = true;
	philo->last_meal = get_elapsed_ms(philo->sim);
	printf("[DEBUG] Philo %d sets last_meal = %ld ms\n", philo->id, philo->last_meal);
	pthread_mutex_unlock(&philo->mutex);
	print_status(philo, "is eating 🍴", GREEN);
	usleep(philo->sim->time_to_eat * 1000);
	pthread_mutex_lock(&philo->mutex);
	philo->meals_eaten++;
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
