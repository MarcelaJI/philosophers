/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:58:35 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/16 09:11:59 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	philo_died(t_philo *philo)
{
	long	last_meal;
	long	now;

	pthread_mutex_lock(&philo->mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->mutex);

	now = get_elapsed_ms(philo->sim);

	if ((now - last_meal) >= philo->sim->time_to_die)
	{
		printf("🛑 PHILO %d DIED — now: %ld, last_meal: %ld, delta: %ld\n",
			philo->id, now, last_meal, now - last_meal);
		return (1);
	}
	return (0);
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
	t_sim	*sim;
	sim = (t_sim *)arg;

	while (!check_death(sim))
		usleep(1000);
	

	return (NULL);
}
