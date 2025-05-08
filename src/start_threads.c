/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:07:23 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/08 20:57:58 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_elapsed_ms(t_sim *sim)
{
	struct timeval	now;
	long			ms;

	gettimeofday(&now, NULL);
	ms = (now.tv_sec - sim->begin_time.tv_sec) * 1000;
	ms += (now.tv_usec - sim->begin_time.tv_usec) / 1000;
	return (ms);
}
