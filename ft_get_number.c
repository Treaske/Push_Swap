/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:43:36 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/14 17:55:26 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_num	ft_inizialice(t_strc_gen *est, int longa)
{
	t_num_gen	s_num;

	s_num.aux = 0;
	s_num.num = 0;
	s_num.x = 0;
	s_num.z = 0;
	s_num.y = 0;
	s_num.a = malloc(sizeof(int) * longa);
	if (!s_num.a)
		est->error = 3;
	return (s_num);
}

struct s_num	ft_make_split(t_num_gen s_num, t_strc_gen est, char **argv)
{
	s_num.auxy = malloc(sizeof(int) * (s_num.countw));
	s_num.auxy = ft_split(argv[s_num.z + 1], est);
	s_num.y = 0;
	s_num.countw = s_num.countw + s_num.x;
	while (s_num.x != s_num.countw)
	{
		s_num.a[s_num.x] = s_num.auxy[s_num.y];
		s_num.y++;
		s_num.x++;
	}
	s_num.x = s_num.countw - 1;
	free(s_num.auxy);
	return (s_num);
}

int	*ft_get_number(int longa, char **argv, t_strc_gen *est)
{
	t_num_gen	s_num;

	s_num = ft_inizialice(est, longa);
	while (s_num.x != longa)
	{
		if (est->error != 0)
			return (0);
		s_num.num = ft_count_arg(argv[s_num.z + 1]);
		if (s_num.num == 0)
			est->error = 4;
		else if (s_num.num == 1)
			s_num.a[s_num.x] = ft_atoi(argv[s_num.z + 1], est);
		else
		{
			s_num = ft_make_split(s_num, *est, argv);
		}
		s_num.x++;
		s_num.z++;
	}
	return (s_num.a);
}