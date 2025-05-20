/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:21:14 by aychikhi          #+#    #+#             */
/*   Updated: 2025/05/20 15:14:04 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// void	one_philo(t_philo *philo)
// {
// 	// printf("0 1 is thinking\n");
// 	// printf("0 1 has taken a fork\n");
// 	think(philo);
// 	pick_up_forks(philo);
// 	ft_usleep(philo, philo->data->time_to_die);
// 	check_death(philo);
// 	// printf("%d 1 died\n", philo->data->time_to_die);
// }

int	read_simulation(t_philo *philo)
{
	int	read;

	pthread_mutex_lock(&philo->data->simulation_mutex);
	read = philo->data->simulation_flag;
	pthread_mutex_unlock(&philo->data->simulation_mutex);
	return (read);
}

void	change_simulation(t_philo *philo, int new_simulation)
{
	pthread_mutex_lock(&philo->data->simulation_mutex);
	philo->data->simulation_flag = new_simulation;
	pthread_mutex_unlock(&philo->data->simulation_mutex);
}

int	read_flag(t_philo *philo)
{
	int	read;

	pthread_mutex_lock(&philo->data->flag_mutex);
	read = philo->data->flag;
	pthread_mutex_unlock(&philo->data->flag_mutex);
	return (read);
}

void	change_flag(t_philo *philo, int new_flag)
{
	pthread_mutex_lock(&philo->data->flag_mutex);
	philo->data->flag = new_flag;
	pthread_mutex_unlock(&philo->data->flag_mutex);
}
