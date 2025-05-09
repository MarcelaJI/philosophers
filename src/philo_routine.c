/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:02:12 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/09 13:11:42 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *philo_routine(void *arg)
{
    t_philo     *philo;

    philo = (t_philo *)arg;
    printf("%ld %d has started\n", get_elapsed_ms(philo->sim), philo->id);
    usleep(1000);
    return (NULL);
}

void    take_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    print_status(philo, "has taken a fork", CYAN);
    pthread_mutex_lock(philo->r_fork);
    print_status(philo, "has taken a fork", CYAN);
}

void philo_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex);
    philo->last_meal = get_elapsed_ms(philo->sim);
    philo->is_eating = true;
    pthread_mutex_unlock(&philo->mutex);
    print_status(philo, "is eating 🍴", GREEN);
    usleep(philo->sim->time_to_eat * 1000); // espera simulando que está comiendo
    pthread_mutex_lock(&philo->mutex);
    philo->meals_eaten++;
    philo->is_eating = false;
    pthread_mutex_unlock(&philo->mutex);
}

void        philo_sleep(t_philo *philo)
{
    print_status(philo, "is sleeping 😴", BLUE);
    usleep(philo->sim->time_to_sleep * 1000);
}

// No necesita dormir (el pensar es inmediato en el ciclo)
void        philo_think(t_philo *philo)
{
    print_status(philo, "is thinking 🤔", MAGENTA);
}
