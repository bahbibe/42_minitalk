/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:36:44 by bahbibe           #+#    #+#             */
/*   Updated: 2023/01/03 14:43:48 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_ack	g_ack;

static void	char_to_bin(int pid, unsigned char c)
{
	int	i;
	int	mod;

	i = 0;
	mod = 0;
	while (i < 8)
	{
		mod = c % 2;
		if (mod != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		c = c / 2;
		usleep(50);
	}
}

static void	handler(void)
{
	g_ack.received_sigs++;
	if (g_ack.received_sigs == g_ack.len * 8)
	{
		ft_putstr_fd("Message sent ✅\n", 1);
		exit(0);
	}
}

static void	send(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_to_bin(pid, (unsigned char)str[i]);
		i++;
	}
	char_to_bin(pid, str[i]);
	char_to_bin(pid, '\n');
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	g_ack.received_sigs = 0;
	g_ack.len = 0;
	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_putstr_fd("Wrong PID\n", 2);
			exit(1);
		}
		g_ack.len = ft_strlen(av[2]) + 2;
		signal(SIGUSR1, (void (*)(int))handler);
		send(pid, av[2]);
		while (1)
			sleep(1);
	}
	else
		ft_putstr_fd("Usage: ./client <server PID> <message>\n", 2);
	return (0);
}
