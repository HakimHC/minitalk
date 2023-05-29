/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:57:21 by hakahmed          #+#    #+#             */
/*   Updated: 2023/05/29 16:58:10 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

#include "minitalk.h"

void	send_bits(char byte, pid_t dest)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((byte >> i) & 1)
			kill(dest, B1);
		else
			kill(dest, B0);
		i--;
		usleep(2);
	}
}

void	send_data(char *data, pid_t dest)
{
	while (*data)
		send_bits(*data++, dest);
	send_bits(0, dest);
}

int	errmsg(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (errmsg("fatal: bad usage\n"));
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (errmsg("fatal: invalid pid\n"));
	send_data(argv[2], pid);
}
