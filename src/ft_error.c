/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:07:25 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/07 09:21:18 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error_exit(char *msg)
{
	printf(RED "%s" RESET, msg);
	exit(EXIT_FAILURE);
}

void	error_parsing(t_sim *table)
{
	(void)table;
	error_exit("Error: Parsing error.\n");
}
