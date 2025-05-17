/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:03:52 by aychikhi          #+#    #+#             */
/*   Updated: 2025/05/17 10:37:48 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_philo *philo)
{
	printf("0 1 is thinking\n");
	printf("0 1 has taken a fork\n");
	ft_usleep(philo, philo->data->time_to_die);
	printf("%d 1 died\n", philo->data->time_to_die);
}

void	clear_fun(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_num)
	{
		pthread_mutex_destroy(&philo[i].left_fork);
		pthread_mutex_destroy(&philo[i].last_meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&philo->data->print_mutex);
	pthread_mutex_destroy(&philo->data->flag_mutex);
	pthread_mutex_destroy(&philo->data->simulation_mutex);
	free(philo->data);
	free(philo);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	if (ac < 5 || ac > 6)
		error_mess();
	check_args(av, ac);
	data = data_init(ac, av);
	philo = malloc(data->philo_num * sizeof(t_philo));
	if (!philo)
		return (free(data), 1);
	philo_init(philo, data);
	if (data->philo_num == 1)
		one_philo(philo);
	else
		thread_create(philo);
	clear_fun(philo);
	return (0);
}
