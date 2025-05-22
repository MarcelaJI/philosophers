/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:42:29 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/22 08:15:47 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error_exit(const char *msg)
{
	printf(RED "%s" RESET, msg);
	exit(EXIT_FAILURE);
}

void	ft_error_parsing(t_sim *sim)
{
	clean_up_all("Error: parsing error\n", sim);
	error_exit("Error: Parsing error");
}