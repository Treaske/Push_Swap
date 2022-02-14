/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:27:49 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/14 17:57:50 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_strc_gen *est)
{
	int	num;
	int	sign;
	int	cont;

	num = 0;
	sign = 1;
	cont = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (str[cont] >= '0' && str[cont] <= '9' && str[cont] != 0)
	{
		num = (num * 10) + (str[cont] - 48);
		cont++;
	}
	if (str[cont] != 0 || num < -2147483648 || num > 2147483647)
	{
		est->error = 1;
		return (0);
	}
	return (num * sign);
}

int	ft_count_arg(char *argv)
{
	int	num;
	int	x;

	num = 0;
	x = 0;
	while (argv[x] != '\0')
	{
		if (argv[x] != ' ')
		{
			num++;
			while (argv[x] != ' ' && argv[x] != '\0')
				x++;
		}
		else if (argv[x] == ' ')
		{
			while (argv[x] == ' ')
				x++;
		}
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
	aux = malloc(sizeof(int) * (countw));
	if (!aux)
		return (NULL);
	while (x != countw)
	{
		while (*s == ' ' && *s != '\0')
			s++;
		aux[x] = get_word(s, &est);
		while (*s != ' ' && *s != '\0')
			s++;
		x++;
	}
	x = 0;
	return (aux);
}