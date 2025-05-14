/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:43:40 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/14 09:01:53 by ingjimen         ###   ########.fr       */
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

