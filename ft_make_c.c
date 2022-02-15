/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:52:25 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/14 17:38:01 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_strc	ft_make_c_aux(t_strc_gen est, int x, int y, int aux)
{
	while (y != est.longa)
	{
		x = 0;
		y = 1;
		while (x + 1 != est.longa)
		{
			if (est.c[x] == est.c[x + 1])
			{
				est.error = 2;
				return (est);
			}
			if (est.c[x] > est.c[x + 1])
			{
				aux = est.c[x];
				est.c[x] = est.c[x + 1];
				est.c[x + 1] = aux;
			}
			else
				y++;
			x++;
		}
	}
	return (est);
}

struct s_strc	ft_make_c(t_strc_gen est, int y)
{
	int	aux;
	int	x;

	x = 0;
	aux = 0;
	y = 1;
	est.c = malloc(sizeof(int) * est.longa);
	while (x != est.longa)
	{
		est.c[x] = est.a[x];
		x++;
	}
	est = ft_make_c_aux(est, x, y, aux);
	return (est);
}