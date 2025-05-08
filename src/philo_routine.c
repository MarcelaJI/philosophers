/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:02:12 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/08 21:10:13 by ingjimen         ###   ########.fr       */
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