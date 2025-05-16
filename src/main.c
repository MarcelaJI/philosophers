/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:07:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/16 09:44:58 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
    t_sim *sim;
    int i;
    long start_ms;
	pthread_t	monitor;

    if (argc < 5 || argc > 6)
        error_exit("Wrong number of arguments\n");

    sim = malloc(sizeof(t_sim));
    if (!sim)
        return (EXIT_FAILURE);

    parse_data(argv, sim);

    init_forks(sim);
    init_philos(sim);

    gettimeofday(&sim->begin_time, NULL);
    start_ms = get_elapsed_ms(sim);

    for (i = 0; i < sim->num_of_philos; i++)
    {
        pthread_mutex_lock(&sim->philos[i].mutex);
        sim->philos[i].last_meal = start_ms;
        pthread_mutex_unlock(&sim->philos[i].mutex);
        printf("[DEBUG] Philo %d last_meal set to %ld\n", sim->philos[i].id, start_ms);
    }

	// Lanzar hilos filósofos
	start_threads(sim);

	// Lanzar monitor
	if (pthread_create(&monitor, NULL, monitor_func, sim) != 0)
		error_exit("Error: Failed to create monitor thread");

	// Liberar a los filósofos para que empiecen
	pthread_mutex_lock(&sim->start_mutex);
	sim->start_sim = true;
	pthread_mutex_unlock(&sim->start_mutex);

	// Esperar a que terminen los hilos filósofos
	for (i = 0; i < sim->num_of_philos; i++)
		pthread_join(sim->philos[i].thread, NULL);

	// Esperar a que termine el monitor
	pthread_join(monitor, NULL);

	// Destruir mutex y liberar memoria
	for (i = 0; i < sim->num_of_philos; i++)
		pthread_mutex_destroy(&sim->forks[i]);
	for (i = 0; i < sim->num_of_philos; i++)
		pthread_mutex_destroy(&sim->philos[i].mutex);
	pthread_mutex_destroy(&sim->start_mutex);
	pthread_mutex_destroy(&sim->dead_lock);

	free(sim->philos);
	free(sim->forks);
	free(sim);

	return (EXIT_SUCCESS);
}

