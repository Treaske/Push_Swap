/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:11:37 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/23 19:49:38 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_strc	ft_rot_a(t_strc_gen estruc)
{
	int	aux;
	int	x;

	write(1, "ra\n", 3);
	x = 0;
	aux = estruc.a[0];
	while (x != (estruc.longa - 1))
	{
		estruc.a[x] = estruc.a[x + 1];
		x++;
	}
	estruc.a[x] = aux;
	estruc.count_mov++;
	return (estruc);
}

struct s_strc	ft_rot_b(t_strc_gen estruc)
{
	int	aux;
	int	x;

	write(1, "rb\n", 3);
	x = 0;
	aux = estruc.b[0];
	while (x != (estruc.longb - 1))
	{
		estruc.b[x] = estruc.b[x + 1];
		x++;
	}
	estruc.b[x] = aux;
	estruc.count_mov++;
	return (estruc);
}

struct s_strc	ft_rot(t_strc_gen estruc)
{
	ft_rot_b(estruc);
	ft_rot_a(estruc);
	estruc.count_mov++;
	return (estruc);
}

struct s_strc	ft_rrot_a(t_strc_gen estruc)
{
	int	aux;
	int	x;

	x = estruc.longa - 2;
	write(1, "rra\n", 4);
	aux = estruc.a[estruc.longa - 1];
	while (x > (1 - 2))
	{
		estruc.a[x + 1] = estruc.a[x];
		x--;
	}
	estruc.a[0] = aux;
	estruc.count_mov++;
	return (estruc);
}

struct s_strc	ft_rrot_b(t_strc_gen estruc)
{
	int	aux;
	int	x;

	x = estruc.longb - 2;
	write(1, "rrb\n", 4);
	aux = estruc.b[estruc.longb - 1];
	while (x > (1 - 2))
	{
		estruc.b[x + 1] = estruc.b[x];
		x--;
	}
	estruc.b[0] = aux;
	estruc.count_mov++;
	return (estruc);
}
