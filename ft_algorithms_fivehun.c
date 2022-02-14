/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms_fivehun.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:37:30 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/14 17:45:53 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_strc	ft_five_hun(t_strc_gen est)
{
	int	j;
	int	y;
	int	i;

	i = 0;
	y = 0;
	j = 0;
 
	while (y != est.longc)
	{   
        printf("\n\na\n\n");
		j = 0;
		while (est.a[y] != est.c[j])
			j++;
		est.a[y] = j;
		y++;
	}
    
	while ((est.c[est.longc - 1] >> i) != 0)
		i++;
	est = ft_five_huntwo(est, i);
	y = 0;
	while (y != est.longc)
	{
		est.a[y] = est.c[y];
		y++;
	}
	return (est);
}

struct s_strc	ft_five_huntwo(t_strc_gen est, int i)
{
	int	y;
	int	j;

	j = 0;
	y = 0;
	while (j != i)
	{	
		while (y < est.longc)
		{
			if (((est.a[0] >> j) & 1) == 0)
				est = ft_pass_a(est);
			else
				est = ft_rot_a(est);
			y++;
		}
		y = est.longb;
		while (y != 0)
		{	
			est = ft_pass_b(est);
			y--;
		}
		j++;
	}
	return (est);
}