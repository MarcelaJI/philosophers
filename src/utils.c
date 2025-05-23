/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:06:53 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/23 09:44:33 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	long		sign;
	long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 &&
				-result < INT_MIN))
			return (-1);
		i++;
	}
	return ((int)(result * sign));
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

long	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_philo *philo, char *status, char *color)
{
	long	timestamp;

	if (philo_has_died(philo))
		return ;
	timestamp = get_current_time_ms() - philo->sim->start_time;
	pthread_mutex_lock(&philo->sim->write_lock);
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

