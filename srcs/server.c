/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:56:26 by hakahmed          #+#    #+#             */
/*   Updated: 2023/05/29 16:59:48 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#include "minitalk.h"

t_info	g_info = {128, 0};

void	wbyte(void)
{
	if (!g_info.flag)
	{
		write(1, &g_info.c, 1);
		if (!g_info.c)
			write(1, "\n", 1);
		g_info = (t_info){128, 0};
	}
}

void	b_one(int signal)
{
	(void) signal;
	g_info.c = g_info.c | g_info.flag;
	g_info.flag /= 2;
	wbyte();
}

void	b_zero(int signal)
{
	(void) signal;
	g_info.flag /= 2;
	wbyte();
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%u\n", pid);
	while (1)
	{
		signal(B1, &b_one);
		signal(B0, &b_zero);
	}
}
