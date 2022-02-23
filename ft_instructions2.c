/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:07:26 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/23 19:49:43 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_strc	ft_swap_a(t_strc_gen estruc)
{
	int	num;

	write(1, "sa\n", 3);
	num = estruc.a[0];
	estruc.a[0] = estruc.a[1];
	estruc.a[1] = num;
	estruc.count_mov++;
	return (estruc);
}

struct s_strc	ft_swap_b(t_strc_gen estruc)
{
	int	num;

	write(1, "sb\n", 3);
	num = estruc.b[0];
	estruc.b[0] = estruc.b[1];
	estruc.b[1] = num;
	estruc.count_mov++;
	return (estruc);
}

struct s_strc	ft_swap(t_strc_gen estruc)
{
	int	num;

	write(1, "ss\n", 3);
	num = estruc.a[0];
	estruc.a[0] = estruc.a[1];
	estruc.a[1] = num;
	num = estruc.b[0];
	estruc.b[0] = estruc.b[1];
	estruc.b[1] = num;
	estruc.count_mov++;
	return (estruc);
}

struct s_strc	ft_rrot(t_strc_gen estruc)
{
	ft_rrot_b(estruc);
	ft_rrot_a(estruc);
	estruc.count_mov++;
	return (estruc);
}
