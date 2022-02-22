/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:50:41 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/21 18:38:08 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*ft_make_auxa(int x, int longa, long *auxa, long *a)
{
	while (x != (longa))
	{
		auxa[x] = a[x - 1];
		x++;
	}
	return (auxa);
}

long	*ft_make_auxb(int longb, long *auxb, long *b)
{
	int	x;

	x = 0;
	while (x != ((longb)))
	{
		auxb[x] = b[x + 1];
		x++;
	}
	return (auxb);
}

struct s_strc	ft_pass_b(t_strc_gen est)
{
	int	x;
	long	*auxa;
	long	*auxb;

	x = 1;
	est.longa++;
	if (est.longb > 0)
		est.longb--;
	write(1, "pa\n", 3);
	auxa = malloc (sizeof(long) * (est.longa));
	auxb = NULL;
	if (est.longb != 0)
		auxb = malloc (sizeof(long) * (est.longb));
	auxa[0] = est.b[0];
	if (est.longa != 1)
		auxa = ft_make_auxa(x, est.longa, auxa, est.a);
	auxb = ft_make_auxb(est.longb, auxb, est.b);
	free(est.a);
	free(est.b);
	if (est.longb != 0)
		est.b = auxb;
	est.a = auxa;
	est.count_mov++;
	return (est);
}

struct s_strc	ft_pass_a(t_strc_gen est)
{
	int	x;
	long	*auxa;
	long	*auxb;

	x = 1;
	est.longb++;
	est.longa--;
	write(1, "pb\n", 3);
	auxa = malloc (sizeof(long) * (est.longa));
	auxb = malloc (sizeof(long) * (est.longb));
	if (est.longb == 1)
			est.b = malloc(sizeof(long) * 1);
	auxb[0] = est.a[0];
	if (est.longb != 1)
		auxb = ft_make_auxa(x, est.longb, auxb, est.b);
	auxa = ft_make_auxb(est.longa, auxa, est.a);
	free(est.a);
	free(est.b);
	est.b = auxb;
	est.a = auxa;
	est.count_mov++;
	return (est);
}