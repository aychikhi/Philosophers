/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:40:55 by aychikhi          #+#    #+#             */
/*   Updated: 2025/05/16 17:41:32 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_mess(void)
{
	ft_putendl_fd("invalid arguments ❌", 2);
	exit(EXIT_FAILURE);
}

size_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

size_t	read_last_meal_time(t_philo *philo)
{
	int	read;

	pthread_mutex_lock(&philo->last_meal_mutex);
	read = philo->last_meal_time;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (read);
}

void	change_last_meal_time(t_philo *philo, size_t new_last_meal_time)
{
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal_time = new_last_meal_time;
	pthread_mutex_unlock(&philo->last_meal_mutex);
}
