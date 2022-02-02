/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:20:34 by rsiqueir          #+#    #+#             */
/*   Updated: 2021/09/29 11:27:43 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_minitalk global;

void init_global()
{
	int bytes;
	int x;

	bytes = 256;
	x = 0;
	while (x < 9)
	{
		global.index[x++] = bytes;
		bytes /= 2;
	}
	global.counter = 0;
	global.new_char = 0;
}

void add_char()
{
	char c[2];
	char *tmp;

	c[0] = global.new_char;
	c[1] = 0;
	tmp = global.word;
	global.word = ft_strjoin(global.word, c);
	free(tmp);
	global.new_char = 0;
}

void handle_new_char()
{
	if (global.new_char == 0)
	{
		ft_printf("%s", global.word);
		free(global.word);
		global.word = 0;
	}
	else
		add_char();
	global.counter = 0;
}

void handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	
	if (!global.word)
		global.word = ft_strdup("");
	if (sig == SIGUSR1)
		global.new_char += global.index[global.counter];
	global.counter++;
	if (global.counter == 9)
		handle_new_char();
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	init_global();
	ft_bzero(&sa, sizeof(sa));
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID: %i\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}