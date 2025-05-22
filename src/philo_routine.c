/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:31:22 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/22 08:17:02 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eat(t_philo *philo)
{
	taken_forks(philo);
	pthread_mutex_lock(&philo->sim->meal_lock);
	philo->eating = 1;
	philo->last_meal = get_current_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->sim->meal_lock);
	print_status(philo, "is eating 🍽️", GREEN);
	ft_usleep(philo->sim->time_to_eat);
	pthread_mutex_lock(&philo->sim->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->sim->meal_lock);
	release_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	if (philo_has_died(philo))
		return ;
	print_status(philo, "is sleeping😴", BLUE);
	ft_usleep(philo->sim->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	if (philo_has_died(philo))
		return ;
	print_status(philo, "is thinking 🤔", MAGENTA);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->sim->time_to_eat / 10);
	;
	while (!philo_has_died(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
