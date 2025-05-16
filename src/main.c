/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:07:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/16 12:42:04 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void    initializatio(char **argv, t_sim *sim)
{
    t_philo *philos;
    pthread_mutex_t *forks;

    sim->philos = NULL;
    sim->forks = NULL;
}

int main(int argc, char **argv)
{
    t_sim sim;

    if (argc != 5 && argc != 6)
    {
        printf("Usage: ./philo num time_to_die time_to_eat time_to_sleep [num_times_to_eat]\n");
        return (1);
    }

    printf("Address of sim in main: %p\n", (void*)&sim);

    parse_data(argv, &sim);

    if (gettimeofday(&sim.begin_time, NULL) != 0)
	{
    	perror("gettimeofday failed");
    	return (1);
	}

    sim.start_time = get_time_in_ms(&sim);
    printf("🟢 begin_time set at: %ld\n", sim.start_time);

    init_forks(&sim);
    init_philos(&sim);

    start_threads(&sim);
    monitor_func(&sim);
    cleanup(&sim);

    return (0);
}
