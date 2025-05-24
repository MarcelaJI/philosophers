/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:06:53 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/24 16:19:46 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_philo *philo, char *status, char *color)
{
	long		timestamp;

	pthread_mutex_lock(&philo->sim->write_lock);
	if (philo_has_died(philo))
	{
		pthread_mutex_unlock(&philo->sim->write_lock);
		return ;
	}
	timestamp = get_current_time_ms() - philo->sim->start_time;
	printf("%s[%ld] %d %s%s\n", CYAN, timestamp, philo->id, color, status);
	printf(RESET);
	pthread_mutex_unlock(&philo->sim->write_lock);
}

void	ft_usleep(long time_in_ms, t_philo *philo)
{
	long	start;
	long	now;

	start = get_current_time_ms();
	while (!philo_has_died(philo))
	{
		now = get_current_time_ms();
		if ((now - start) >= time_in_ms)
			break ;
		usleep(500);
	}
}

int	philo_has_died(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->sim->dead_lock);
	result = philo->sim->someone_died;
	pthread_mutex_unlock(&philo->sim->dead_lock);
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
