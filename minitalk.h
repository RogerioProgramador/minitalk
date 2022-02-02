/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:31:19 by rsiqueir          #+#    #+#             */
/*   Updated: 2021/09/20 21:36:12 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define PID_ERROR "Invalid PID.\n"
# define USAGE_ERROR "Invalid usage.\nCorrect Usage: ./client <server_pid> <your_string>\n"
# define ALLOC_ERROR "Allocation error.\n"
# define SUCCESS "Message sent successfully."

# include <signal.h>
# include <unistd.h>
# include "ft_printf/include/ft_printf.h"

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
#endif
