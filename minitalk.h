/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:31:19 by rsiqueir          #+#    #+#             */
/*   Updated: 2022/02/22 04:21:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define PID_ERROR "Invalid PID.\n"
# define USAGE_ERROR "Invalid Usage.\nCorrect Usage: ./client <pid> <string>"
# define SUCCESS "Message sent successfully."

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_client
{
	int		pid;
	char	*message;
}			t_client;

typedef struct s_minitalk
{
	int		index[9];
	int		counter;
	int		new_char;
	char	*word;
}			t_minitalk;

void	ft_bzero(void *s, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);

int		ft_atoi(const char *str);

char	*ft_strdup(char *s1);

void	print_char(char c);

void	print_string(char *s);

void	print_number(int n);

#endif
