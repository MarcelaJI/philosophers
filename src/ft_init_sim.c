/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 08:36:11 by ingjimen          #+#    #+#             */
/*   Updated: 2025/05/07 10:09:39 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    init_forks(t_sim *sim)
{
    int     i;

    sim->forks = malloc(sizeof(pthread_mutex_t) * sim->num_of_philos);
    if (!sim->forks)
        error_exit("Fork initialization failed\n");
    i = 0;
    while (i < sim->num_of_philos)
    {
        pthread_mutex_init(&sim->forks[i], NULL);
        i++;
    }
}
/*Estoy utlizando tenedor circular porque los filósofos están en un círculo. El módulo hace
que el índice "Vuelva al principio" cuando llega al final, simulando esa forma circular en la mesa.
Porque el último filósofo (por ejemplo, el número 4), su tenedor derecho es el tenedor 0, no hay un fork[5].
Si index = 4 y num_of_philos = 5,
entonces: (4 + 1) % 5 = 0
Así el filósofo 4 usa el tenedor 0 como su tenedor derecho*/
static void     assign_forks(t_philo *philo, int index, t_sim *sim)
{
	philo->l_fork = &sim->forks[index];
	philo->r_fork = &sim->forks[(index + 1) % sim->num_of_philos];
}

void     init_philos(t_sim *sim)
{
    int     i;

    sim->philos = malloc(sizeof(t_philo) * sim->num_of_philos);
    if (!sim->philos)
        error_exit("Failed to allocate memory for philosophers\n");
    i = 0;
    while (i < sim->num_of_philos)
    {
        sim->philos[i].id = i + 1; // Le asigno un ID humano (empiza en 1, no en 0)
        sim->philos[i].meals_eaten = 0; // Inicializo el número de comidas a 0
        sim->philos[i].last_meal = 0; // Lo pongo en 0 y se actualiza cuando empiece la simulación
        sim->philos[i].sim = sim; // guardo un puntero al struct global, por si lo necesito dentro de su rutina. Así no tengo que pasar mil argumentos en todas las funciones.
        pthread_mutex_init(&sim->philos[i].mutex, NULL);
        assign_forks(&sim->philos[i], i, sim);
        i++;
    }
}