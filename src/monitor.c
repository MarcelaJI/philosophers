/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:01:41 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/23 10:35:37 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_died(t_philo *philo, size_t time)
{
	int		result;
	long	current_time;
	long	last_meal;
	long	diff;

	result = 0;
	current_time = get_current_time_ms();
	pthread_mutex_lock(&philo->sim->meal_lock);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->sim->meal_lock);
	diff = current_time - last_meal;
	if (diff >= (long)time)
	{
		result = 1;
	}
	return (result);
}

int	check_death(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_of_philos)
	{
		if (philo_died(&sim->philos[i], sim->time_to_die))
		{
			pthread_mutex_lock(&sim->dead_lock);
			sim->someone_died = 1;
			printf(RED "%ld %d died 💀\n" RESET, get_current_time_ms()
				- sim->start_time, sim->philos[i].id);
			pthread_mutex_unlock(&sim->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_sim *sim)
{
	int	i;
	int	finished_eating;

	if (sim->number_of_times_each_philosopher_must_eat == -1)
		return (0);
	finished_eating = 0;
	i = 0;
	while (i < sim->num_of_philos)
	{
		pthread_mutex_lock(&sim->meal_lock);
		if (sim->philos[i].meals_eaten >= sim->number_of_times_each_philosopher_must_eat)
			finished_eating++;
		pthread_mutex_unlock(&sim->meal_lock);
		i++;
	}
	if (finished_eating == sim->num_of_philos)
	{
		pthread_mutex_lock(&sim->dead_lock);
		sim->someone_died = 1;
		pthread_mutex_unlock(&sim->dead_lock);
		printf(YELLOW "[%ld] YELLOW All philosophers are full 🐷🍝😊\n" RESET,
			get_current_time_ms() - sim->start_time);
		return (1);
	}
	return (0);
}

int	philo_has_died(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->sim->dead_lock);
	result = philo->sim->someone_died;
	pthread_mutex_unlock(&philo->sim->dead_lock);
	return (result);
}

void	*monitor_func(void *arg)
{
	t_sim	*sim;

	sim = (t_sim *)arg;
	while (1)
	{
		if (check_death(sim) || check_if_all_ate(sim))
			break ;
		usleep(1000);
	}
	return (NULL);
}
