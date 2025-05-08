/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:07:23 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/08 21:00:49 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_elapsed_ms(t_sim *sim)
{
	struct timeval	now;
	long			ms;

	gettimeofday(&now, NULL);
	ms = (now.tv_sec - sim->begin_time.tv_sec) * 1000;
	ms += (now.tv_usec - sim->begin_time.tv_usec) / 1000;
	return (ms);
}

void	start_threads(t_sim *sim)
{
	int	i;

	gettimeofday(&sim->begin_time, NULL);  // Guarda el tiempo de inicio
	i = 0;
	while (i < sim->num_of_philos)
	{
		sim->philos[i].last_meal = get_elapsed_ms(sim);  // tiempo relativo 0 para todos

		if (pthread_create(&sim->philos[i].thread, NULL, philo_routine, &sim->philos[i]) != 0)
			error_exit("Error: Failed to create thread\n");
		i++;
	}
}
