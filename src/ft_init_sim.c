/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 08:36:11 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/07 08:52:39 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    init_forks(t_sim *sim)
{
    int     i;

    i = 0;
    sim->forks = malloc(sizeof(pthread_mutex_t) * sim->num_of_philos);
    if (!sim->forks)
        error_exit("Fork initialization failed\n");
    while (i < sim->num_of_philos)
    {
        pthread_mutex_init(&sim->forks[i], NULL);
        i++;
    }
}