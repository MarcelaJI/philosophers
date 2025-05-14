/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:07:23 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/14 08:48:20 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_elapsed_ms(t_sim *sim)
{
	struct timeval	current;
	long			sec;
	long			usec;

	gettimeofday(&current, NULL);
	sec = current.tv_sec - sim->begin_time.tv_sec;
	usec = current.tv_usec - sim->begin_time.tv_usec;
	return (sec * 1000 + usec / 1000);
}

void	wait_all_threads(t_sim *sim)
{
	pthread_mutex_lock(&sim->start_mutex);
	while (!sim->start_sim)
	{
		pthread_mutex_unlock(&sim->start_mutex);
		usleep(100);
		pthread_mutex_lock(&sim->start_mutex);
	}
	pthread_mutex_unlock(&sim->start_mutex);
}

void	start_threads(t_sim *sim)
{
	int	i;
	t_philo	*philo;

	i = 0;
	while (i < sim->num_of_philos)
	{
		philo = &sim->philos[i];
		pthread_mutex_lock(&philo->mutex);
		philo->last_meal = get_elapsed_ms(sim);
		pthread_mutex_unlock(&philo->mutex);
		printf("🕒 SET last_meal for philo %d = %ld\n", philo->id, philo->last_meal);
		if (pthread_create(&philo->thread, NULL, philo_routine, philo) != 0)
			error_exit("Error: Failed to create thread\n");
		i++;
	}
}





