/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_algorithms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:12:28 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/18 19:13:26 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_strc handle_swaps(t_strc_gen est)
{
	int	x;
	
	x = 0;
	while (x != est.longa)
		x++;
	est.mid = est.c[est.longa / 2];
	if (est.longa <= 3)
		est = ft_three(est);
	else if (est.longa <= 100)
		est = ft_one_hun(est);
	else
		est = ft_five_hun(est);
	return (est);
}