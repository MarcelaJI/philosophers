/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:31:22 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/23 11:01:03 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eat(t_philo *philo)
{
	long	timestamp;

	taken_forks(philo);

	pthread_mutex_lock(&philo->sim->meal_lock);
	philo->eating = 1;
	philo->last_meal = get_current_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->sim->meal_lock);
	print_status(philo, "is eating 🍽️", GREEN);
	ft_usleep(philo->sim->time_to_eat, philo);
	pthread_mutex_lock(&philo->sim->meal_lock);
	if (philo->sim->number_of_times_each_philosopher_must_eat != -1
		&& philo->meals_eaten == philo->sim->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&philo->sim->full_lock);
		philo->sim->full_philos++;
		if (philo->sim->full_philos == philo->sim->num_of_philos)
		{
			timestamp = get_current_time_ms() - philo->sim->start_time;
			pthread_mutex_lock(&philo->sim->write_lock);
			printf(YELLOW "[%ld] All philosophers have eaten %d times 🐷😝\n" RESET,
				timestamp, philo->sim->number_of_times_each_philosopher_must_eat);
			pthread_mutex_unlock(&philo->sim->write_lock);
		}
		pthread_mutex_unlock(&philo->sim->full_lock);
	}
	philo->eating = 0;
	pthread_mutex_unlock(&philo->sim->meal_lock);
	release_forks(philo);
}



void philo_sleep(t_philo *philo)
{
	if (philo_has_died(philo))
		return ;
	print_status(philo, "is sleeping 😴", BLUE);
	ft_usleep(philo->sim->time_to_sleep, philo);
}


void philo_think(t_philo *philo)
{
	if (philo_has_died(philo))
		return ;
	print_status(philo, "is thinking 🤔", MAGENTA);
}

int	philo_has_died(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->sim->dead_lock);
	result = philo->sim->someone_died;
	pthread_mutex_unlock(&philo->sim->dead_lock);
	return (result);
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

