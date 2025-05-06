/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:07:25 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/06 09:05:46 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error_exit(char *msg)
{
	printf(RED "%s" RESET, msg);
	exit(EXIT_FAILURE);
}

void	error_argv(void)
{
	error_exit("Error: Number of incorrect arguments\n");
}

void	error_parsing(t_philo_sim *table)
{
	(void)table;
	error_exit("Error: Argument parsing failed.\n");
}