/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:31:22 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/22 21:59:15 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void philo_eat(t_philo *philo)
{
	taken_forks(philo);

	pthread_mutex_lock(&philo->sim->meal_lock);
	philo->eating = 1;
	philo->last_meal = get_current_time_ms();
	philo->meals_eaten++;
    printf(YELLOW "[%ld] Philosopher %d starts eating (last_meal = %ld)\n" RESET,
	    get_current_time_ms() - philo->sim->start_time, philo->id, philo->last_meal);
	pthread_mutex_unlock(&philo->sim->meal_lock);

	print_status(philo, "is eating 🍽️", GREEN);
	ft_usleep(philo->sim->time_to_eat, philo);

	if (philo_has_died(philo))
	{
		release_forks(philo);
		return;
	}

	pthread_mutex_lock(&philo->sim->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->sim->meal_lock);

	release_forks(philo);
}

void philo_sleep(t_philo *philo)
{
	if (philo_has_died(philo))
		return ;
	print_status(philo, "is sleeping😴", BLUE);
	printf(CYAN "[%ld] Philosopher %d goes to sleep\n" RESET,
		get_current_time_ms() - philo->sim->start_time, philo->id);
	ft_usleep(philo->sim->time_to_sleep, philo);
}


void philo_think(t_philo *philo)
{
	if (philo_has_died(philo))
		return;
	print_status(philo, "is thinking 🤔", MAGENTA);
	ft_usleep(50, philo);  // Pensamiento breve para evitar starvation
}

void *philo_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	if (philo->sim->num_of_philos == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork", CYAN);
		ft_usleep(philo->sim->time_to_die, philo);
		pthread_mutex_unlock(philo->l_fork);
		print_status(philo, "died 💀", RED);
		return NULL;
	}
	if (philo->id % 2 == 0)
		ft_usleep(philo->sim->time_to_eat / 10, philo);

	while (!philo_has_died(philo))
	{
		philo_eat(philo);
		if (philo_has_died(philo))
			break;
		philo_sleep(philo);
		if (philo_has_died(philo))
			break;
		philo_think(philo);
	}
	return NULL;
}

