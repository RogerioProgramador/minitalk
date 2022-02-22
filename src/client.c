/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:26:47 by rsiqueir          #+#    #+#             */
/*   Updated: 2022/02/22 04:10:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_hold = 1;

static void	handle_signal(int sig)
{
	(void)sig;
	g_hold = 0;
}

int	send_char(char a, int pid)
{
	int	i;

	i = 1 << 8;
	signal(SIGUSR1, handle_signal);
	while (i)
	{
		if (i & a)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		i >>= 1;
		while (g_hold)
		{
		}
		g_hold = 1;
	}
	return (1);
}

int	send_message(char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i])
	{
		if (!send_char(message[i], pid))
			return (0);
		i++;
	}
	i = 0;
	signal(SIGUSR1, handle_signal);
	while (i < 9)
	{
		kill(pid, SIGUSR2);
		i++;
		while (g_hold)
		{
		}
		g_hold = 1;
	}
	return (1);
}

int	print_and_return(char *string, int return_value, char **message)
{
	print_string(string);
	print_string("\n");
	if (message)
		free(*message);
	return (return_value);
}

int	main(int argc, char **argv)
{
	t_client	client;

	if (argc != 3)
		return (print_and_return(USAGE_ERROR, 1, 0));
	client.pid = ft_atoi(argv[1]);
	client.message = ft_strdup(argv[2]);
	if (!client.message[0])
		return (print_and_return(USAGE_ERROR, 1, &client.message));
	if (client.pid <= 0)
		return (print_and_return(PID_ERROR, 1, &client.message));
	if (!send_message(client.message, client.pid))
		return (print_and_return(PID_ERROR, 1, &client.message));
	return (print_and_return(SUCCESS, 0, &client.message));
}
