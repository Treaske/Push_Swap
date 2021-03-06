/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:43:36 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/23 19:21:31 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_num	ft_inizialice_a(t_strc_gen *est, int longa)
{
	t_num_gen	s_num;

	s_num.aux = 0;
	s_num.num = 0;
	s_num.x = 0;
	s_num.z = 1;
	s_num.y = 0;
	s_num.a = malloc(sizeof(long) * longa);
	if (!s_num.a)
		est->error = 3;
	return (s_num);
}

struct s_num	ft_make_split(t_num_gen s_num, t_strc_gen est, char **argv)
{
	int	*free_int;

	free_int = ft_split(argv[s_num.z], est);
	s_num.countw = ft_count_arg(argv[s_num.z]);
	if (free_int == 0)
		est.error = 8;
	else
		s_num.auxy = ft_split(argv[s_num.z], est);
	s_num.y = 0;
	if (est.error != 0)
		return (s_num);
	free(free_int);
	if (s_num.z == 1)
		s_num.x = 1;
	s_num.x--;
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

struct s_num	ft_get_number_aux(t_num_gen s_num, t_strc_gen *est, char **argv)
{
	s_num.num = ft_count_arg(argv[s_num.z]);
	if (est->error != 0)
	{
		if (est->error == 0)
			ft_check_error(*est, est->longa);
		return (s_num);
	}
	if (s_num.num == 1)
	{
		s_num.a[s_num.x] = ft_atoi(argv[s_num.z], est);
		s_num.x++;
		s_num.z++;
	}
	else if (s_num.num > 1)
	{
		s_num.x = s_num.x + 1;
		s_num = ft_make_split(s_num, *est, argv);
		s_num.x++;
		s_num.z++;
	}
	return (s_num);
}

long	*ft_get_number(int longa, char **argv, t_strc_gen *est)
{
	t_num_gen	s_num;

	s_num = ft_inizialice_a(est, longa);
	while (s_num.x != longa)
	{
		if (argv[s_num.z][0] == 0)
		{
			while ((argv[s_num.z][0] == 0) && argv[s_num.z])
				s_num.z++;
			if (!argv[s_num.z])
				return (s_num.a);
		}
		if (argv[s_num.z][0] == ' ')
		{
			while ((argv[s_num.z][0] == ' ') && argv[s_num.z])
				argv[s_num.z]++;
			if (!argv[s_num.z])
				return (s_num.a);
		}
		s_num = ft_get_number_aux(s_num, est, argv);
	}
	return (s_num.a);
}
