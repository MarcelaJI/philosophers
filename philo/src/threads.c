/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:30:19 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/23 11:42:09 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	create_threads(t_sim *sim, pthread_t *monitor_thread)
{
	int	i;

	sim->start_time = get_current_time_ms();
	i = 0;
	while (i < sim->num_of_philos)
	{
		sim->philos[i].last_meal = sim->start_time;
		i++;
	}
	if (pthread_create(monitor_thread, NULL, monitor_func, sim) != 0)
		clean_up_all("Failed to create monitor thread\n", sim);
	i = 0;
	while (i < sim->num_of_philos)
	{
		if (pthread_create(&sim->philos[i].thread, NULL, philo_routine,
				&sim->philos[i]) != 0)
			clean_up_all("Failed to create philosopher thread\n", sim);
		i++;
	}
}

static void	join_threads(t_sim *sim, pthread_t *monitor_thread)
{
	int	i;

	if (pthread_join(*monitor_thread, NULL) != 0)
		clean_up_all("Thread join error\n", sim);
	i = 0;
	while (i < sim->num_of_philos)
	{
		if (pthread_join(sim->philos[i].thread, NULL) != 0)
			clean_up_all("Thread join error\n", sim);
		i++;
	}
}

void	start_threads(t_sim *sim)
{
	pthread_t	monitor_thread;

	create_threads(sim, &monitor_thread);
	join_threads(sim, &monitor_thread);
}
