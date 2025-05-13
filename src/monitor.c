/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:58:35 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/13 10:20:50 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	philo_died(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->mutex);
	time = get_elapsed_ms(philo->sim) - philo->last_meal;
	pthread_mutex_unlock(&philo->mutex);
	return (time >= philo->sim->time_to_die);
}

int	check_death(t_sim *sim)
{
	int		i;

	i = 0;
	while (i < sim->num_of_philos)
	{
		if (philo_died(&sim->philos[i]))
		{
			pthread_mutex_lock(&sim->dead_lock);
			if (!sim->someone_died)
			{
				print_status(&sim->philos[i], "died", RED);
				sim->someone_died = 1;
			}
			pthread_mutex_unlock(&sim->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor_func(void *arg)
{
	t_sim	*sim = (t_sim *)arg;

	while (!check_death(sim))
		usleep(1000);
	return (NULL);
}
