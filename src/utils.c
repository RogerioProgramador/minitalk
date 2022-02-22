/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:31:06 by coder             #+#    #+#             */
/*   Updated: 2022/02/22 04:22:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*pointer;

	a = 0;
	b = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	while (s1[a])
		a++;
	while (s2[b])
		b++;
	pointer = malloc(a + b + 1);
	if (!(pointer))
		return (0);
	a = -1;
	b = 0;
	while (s1[++a])
		pointer[a] = s1[a];
	while (s2[b])
		pointer[a++] = s2[b++];
	pointer[a] = 0;
	return (pointer);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((*str == '\t') || (*str == '\v') || (*str == '\f') || (*str == '\r')
		|| (*str == ' ') || (*str == '\n'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && str[i] >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	dest = malloc(i + 1);
	if (!(dest))
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	print_string(char *s)
{
	if (s == 0)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	print_number(int n)
{
	char	x;

	if (n == -2147483648)
	{
		print_string("-2147483648");
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= 10)
		print_number((n / 10));
	x = (n % 10) + '0';
	write(1, &x, 1);
}
