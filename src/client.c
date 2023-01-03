/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:36:44 by bahbibe           #+#    #+#             */
/*   Updated: 2023/01/03 02:23:41 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	char_to_bin(int pid, unsigned char c)
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

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	i = 0 ;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_putstr_fd("Wrong PID\n", 2);
			exit(1);
		}
		while (av[2][i])
		{
			char_to_bin(pid, (unsigned char)av[2][i]);
			i++;
		}
		char_to_bin(pid, av[2][i]);
		char_to_bin(pid, '\n');
	}
	else
		ft_putstr_fd("Usage: ./client <server PID> <message>\n", 2);
	return (0);
}
