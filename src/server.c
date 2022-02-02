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

t_minitalk	g_struct;

void	init_global(void)
{
	int	bytes;
	int	x;

	bytes = 256;
	x = 0;
	while (x < 9)
	{
		g_struct.index[x++] = bytes;
		bytes /= 2;
	}
	g_struct.counter = 0;
	g_struct.new_char = 0;
}

void	add_char(void)
{
	char	c[2];
	char	*tmp;

	c[0] = g_struct.new_char;
	c[1] = 0;
	tmp = g_struct.word;
	g_struct.word = ft_strjoin(g_struct.word, c);
	free(tmp);
	g_struct.new_char = 0;
}

void	handle_new_char(void)
{
	if (g_struct.new_char == 0)
	{
		ft_printf("%s", g_struct.word);
		free(g_struct.word);
		g_struct.word = 0;
	}
	else
		add_char();
	g_struct.counter = 0;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_struct.word)
		g_struct.word = ft_strdup("");
	if (sig == SIGUSR1)
		g_struct.new_char += g_struct.index[g_struct.counter];
	g_struct.counter++;
	if (g_struct.counter == 9)
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
