/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:07:14 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/30 14:43:59 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Comprueba que el input sea solo números

int   is_only_digits(char *argv)
{
    int i;

    i = 0;
    if (!argv || argv[0] == '\0')
        return (0);
    while (argv[i] != '\0')
    {
        if (argv[i] < '0' || argv[i] > '9')
            return (0); // No es dígito
        i++;
    }
    return (1);
}

// Chequear si el input del programa es correcto
int check_program_input(char **argv, int argc)
{
    if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0 || !is_only_digits(argv[1]))
        return (write(2, "Invalid philosophers number\n", 29), EXIT_FAILURE);
    if (ft_atoi(argv[2]) <= 0 || !is_only_digits(argv[2]))
        return (write(2, "Invalid time to die\n", 21), EXIT_FAILURE);
    if (ft_atoi(argv[3]) <= 0 || !is_only_digits(argv[3]))
        return (write(2, "Invalid time to eat\n", 21), EXIT_FAILURE);
    if (ft_atoi(argv[4]) <= 0 || !is_only_digits(argv[4]))
        return (write(2, "Invalid time to sleep\n", 23), EXIT_FAILURE);
    if (argc == 6)
    {
        if (ft_atoi(argv[5]) <= 0 || !is_only_digits(argv[5]))
            return (write(2, "Invalid number of times each philosopher must eat\n", 51), EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
    if (argc != 5 && argc != 6)
        return (write(2, "Number of incorrect arguments\n", 31), EXIT_FAILURE);

    if (check_program_input(argv, argc) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}