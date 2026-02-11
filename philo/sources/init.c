/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:30:40 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/11/24 17:52:56 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * table->nb_philos);
	if (!forks)
		return (error_null(STR_ERR_MALLOC, NULL, table));
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (error_null(STR_ERR_MUTEX, NULL, table));
		i++;
	}
	return (forks);
}

static void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->nb_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->nb_philos;
		philo->fork[1] = philo->id;
	}
}

static t_philo	**init_philosophers(t_table *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo *) * table->nb_philos);
	if (!philos)
		return (error_null(STR_ERR_MALLOC, NULL, table));
	i = 0;
	while (i < table->nb_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i] || pthread_mutex_init(&philos[i]->meal_time_lock, NULL))
		{
			while (i > 0)
				free(philos[--i]);
			free(philos);
			return (error_null(STR_ERR_MALLOC, NULL, table));
		}
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->times_ate = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

static bool	init_global_mutexes(t_table *table)
{
	table->fork_locks = init_forks(table);
	if (!table->fork_locks)
		return (false);
	if (pthread_mutex_init(&table->sim_stop_lock, NULL) != 0)
	{
		error_failure(STR_ERR_MUTEX, NULL, table);
		return (false);
	}
	if (pthread_mutex_init(&table->write_lock, NULL) != 0)
	{
		error_failure(STR_ERR_MUTEX, NULL, table);
		return (false);
	}
	return (true);
}

t_table	*init_table(int argc, char **argv, int i)
{
	t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	if (!table)
		return (error_null(STR_ERR_MALLOC, NULL, 0));
	table->nb_philos = integer_atoi(argv[i++]);
	table->time_to_die = integer_atoi(argv[i++]);
	table->time_to_eat = integer_atoi(argv[i++]);
	table->time_to_sleep = integer_atoi(argv[i++]);
	table->must_eat_count = -1;
	if (argc - 1 == 5)
		table->must_eat_count = integer_atoi(argv[i]);
	table->philos = init_philosophers(table);
	if (!table->philos)
	{
		free(table);
		return (NULL);
	}
	if (!init_global_mutexes(table))
	{
		free_table(table);
		return (NULL);
	}
	table->sim_stop = false;
	return (table);
}
