/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:43:40 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/16 09:57:18 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int philo_has_died(t_philo *philo)
{
    int result;

    pthread_mutex_lock(&philo->sim->dead_lock);
    result = philo->sim->someone_died;
    pthread_mutex_unlock(&philo->sim->dead_lock);
    return (result);
}

void release_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
}



bool should_continue(t_philo *philo)
{
    return (!philo_has_died(philo));
}

void init_last_meals(t_sim *sim)
{
	int		i;
	long	start_ms;
    start_ms = get_elapsed_ms(sim);

    i = 0;
	while (i < sim->num_of_philos)
	{
		pthread_mutex_lock(&sim->philos[i].mutex);
		sim->philos[i].last_meal = start_ms;
		pthread_mutex_unlock(&sim->philos[i].mutex);
		printf("[DEBUG] Philo %d starts with last_meal = %ld\n",
			sim->philos[i].id, start_ms);
        i++;
	}
}

