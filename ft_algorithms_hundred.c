/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms_hundred.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:10:26 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/14 17:47:53 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_lower(t_strc_gen est)
{
	int	x;

	x = 0;
	while (x < est.longa)
	{
		if (est.a[x] <= est.mid)
			return (1);
		x++;
	}
	return (0);
}

int	ft_get_count(t_strc_gen *est)
{
	int	count;
	int	x;

	x = 0;
	count = 0;
	while (est->b[count] != est->c[est->longc - est->aux])
		count++;
	if (count < (est->longb / 2))
		return (1);
	return (2);
}

struct s_strc	ft_one_hun(t_strc_gen est)
{
	int	x;
	int	aux;

	x = 2;
	aux = 0;
	while (est.longa != 2)
	{
		if (est.longa % 2 == 0)
			aux += (est.longa / 2) - 1;
		else
			aux += (est.longa / 2);
		est.mid = est.c[aux];
		while (ft_check_lower(est) != 0 && est.longa != 2)
		{
			if (est.a[0] <= est.mid)
				est = ft_pass_a(est);
			else
				est = ft_rot_a(est);
		}
	}
	if (est.a[0] > est.a[1])
		est = ft_swap_a(est);
	est = ft_one_huntwo(est);
	return (est);
}

struct s_strc	ft_one_huntwo(t_strc_gen est)
{
	while (est.longa != est.longc)
	{
		if (ft_get_count(&est) == 1)
		{
			if (est.b[0] != est.c[est.longc - est.aux])
			{
				while (est.b[0] != est.c[est.longc - est.aux])
					est = ft_rot_b(est);
			}
		}
		else
		{
			if (est.b[0] != est.c[est.longc - est.aux])
			{
				while (est.b[0] != est.c[est.longc - est.aux])
					est = ft_rrot_b(est);
			}
		}
		est.aux++;
		est = ft_pass_b(est);
	}
	return (est);
}