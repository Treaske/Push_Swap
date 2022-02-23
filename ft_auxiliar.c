/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:47:48 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/23 18:44:52 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error_aux(t_strc_gen est)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != est.longa)
	{
		if (est.a[x] == est.c[x])
			y++;
		x++;
	}
	return (y);
}

int	ft_check_error(t_strc_gen est, int argc)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (argc == 1 || est.longa == 1 || est.longa == 0)
	{
		if (est.longa == 1)
			free(est.a);
		return (1);
	}
	if (est.error == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (est.error != 0)
		return (handle_error(0, est));
	if (!est.c)
		return (0);
	y = ft_check_error_aux(est);
	if (y == est.longa)
		return (handle_error(1, est));
	return (0);
}

int	ft_check_letters(char **argv, int argc)
{
	int	x;

	x = 1;
	while (x != argc)
	{
		if (ft_count_arg(argv[x]) == 0 && argv[x][0] != 0 && argv[x][0] != ' ')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (ft_len(argv[x]) >= 11)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		x++;
	}
	return (1);
}
