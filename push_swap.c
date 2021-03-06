/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:47:48 by ade-blas          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:47 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_long_args(int argc, char **argv)
{
	int	cont;
	int	x;

	x = 1;
	cont = 0;
	while (x != argc)
	{
		if (ft_count_arg(argv[x]) == 1)
			cont++;
		else if (ft_count_arg(argv[x]) > 1)
			cont += ft_count_arg(argv[x]);
		x++;
	}
	return (cont);
}

//void	leaks(void)
//{
//	system("leaks -q push_swap");
//}

int	ft_check_lowmax(t_strc_gen est)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != est.longa)
	{
		if (est.a[x] <= -2147483648 || est.a[x] >= 2147483647)
			y++;
	x++;
	}
	return (y);
}

static struct s_strc	ft_inicialize(int argc, char **argv)
{
	t_strc_gen	est;

	est.error = 0;
	est.longa = ft_get_long_args(argc, argv);
	if (est.longa == 0)
	{
		est.error = 7;
		return (est);
	}
	est.longb = 0;
	est.aux = 3;
	est.count_mov = 0;
	est.a = ft_get_number(est.longa, argv, &est);
	est.longc = est.longa;
	return (est);
}

int	handle_error(int flg, t_strc_gen est)
{
	if (flg == 0)
		write(1, "Error\n", 6);
	else
	{
		free(est.a);
		if (est.c)
			free(est.c);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_strc_gen	est;

	if (argc == 1)
		return (0);
	if (argc == 2 && ft_count_arg(argv[1]) == 1)
		return (0);
	if (ft_check_letters(argv, argc) == 0)
		return (0);
	est = ft_inicialize(argc, argv);
	if (ft_check_error(est, argc) != 0)
		return (0);
	est = ft_make_c(est);
	if (ft_check_error(est, argc) != 0)
		return (0);
	est.mid = est.c[est.longa / 2];
	if (est.longa <= 3)
		est = ft_three(est);
	else if (est.longa <= 100)
		est = ft_one_hun(est);
	else
		est = ft_five_hun(est);
	free(est.a);
	free(est.c);
	return (0);
}
