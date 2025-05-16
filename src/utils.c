/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:00:47 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/16 10:10:52 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			return (-1);
		i++;
	}
	return ((int)(result * sign));
}

void	print_status(t_philo *philo, char *msg, char *color)
{
	long	timestamp;

	pthread_mutex_lock(&philo->sim->write_lock);
	timestamp = get_time_in_ms(philo->sim);
	if (!philo->sim->someone_died)
		printf("%s%ld %d %s%s\n", color, timestamp, philo->id, msg, RESET);
	pthread_mutex_unlock(&philo->sim->write_lock);
}

void cleanup(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_of_philos)
		pthread_mutex_destroy(&sim->forks[i++]);
	free(sim->forks);
	i = 0;
	while (i < sim->num_of_philos)
		pthread_mutex_destroy(&sim->philos[i++].mutex);
	free(sim->philos);
	pthread_mutex_destroy(&sim->write_lock);
	pthread_mutex_destroy(&sim->dead_lock);
}