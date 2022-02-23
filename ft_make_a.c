/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:27:49 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/23 19:04:27 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_strc_gen *est)
{
	long	num;
	int		sign;
	int		cont;

	num = 0;
	sign = 1;
	cont = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (str[cont] >= '0' && str[cont] <= '9')
	{
		num = (num * 10) + (str[cont] - 48);
		cont++;
	}
	if (cont >= 11)
		est->error = 1;
	if (str[cont] != 0 || num <= -2147483648 || num >= 2147483647)
		est->error = 1;
	return (num * sign);
}

int	ft_count_arg(char *str)
{
	int	num;
	int	x;

	num = 0;
	x = 0;
	while (str[x] != 0)
	{
		if (str[x] >= '0' && str[x] <= '9')
		{
			while (str[x] >= '0' && str[x] <= '9')
				x++;
			num++;
		}
		else if (str[x] == ' ' || str[x] == '+' || str[x] == '-')
		{
			while (str[x] == ' ' || str[x] == '+' || str[x] == '-')
				x++;
		}
		else
			return (0);
	}
	return (num);
}

int	ft_len(char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0' && s[x] != ' ')
		x++;
	return (x);
}

int	get_word(char *s, t_strc_gen *est)
{
	int		x;
	int		wlen;
	char	*aux;

	x = 0;
	wlen = ft_len(s);
	if (wlen >= 11)
		est->error = 9;
	aux = malloc(sizeof(char) * wlen + 1);
	if (!aux)
		return (0);
	x = 0;
	while (x != wlen)
	{
		aux[x] = s[x];
		x++;
	}
	aux[x] = '\0';
	x = ft_atoi(aux, est);
	free(aux);
	return (x);
}

int	*ft_split(char *s, t_strc_gen est)
{
	int	*aux;
	int	x;
	int	countw;

	x = 0;
	if (!s)
		return (NULL);
	countw = ft_count_arg(s);
	if (countw == 0)
		return (0);
	aux = malloc(sizeof(int) * (countw));
	if (!aux)
		return (NULL);
	while (x != countw)
	{
		while (*s == ' ' && *s != '\0')
			s++;
		aux[x] = get_word(s, &est);
		if (est.error != 0)
			return (0);
		while (*s != ' ' && *s != '\0')
			s++;
		x++;
	}
	return (aux);
}
