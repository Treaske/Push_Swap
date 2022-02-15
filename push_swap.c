/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:47:48 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/24 18:05:54 by ade-blas         ###   ########.fr       */
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
		else
			cont += ft_count_arg(argv[x]);
		x++;
	}
	return (cont);
}

static struct s_strc	ft_inicialize(int argc, char **argv)
{
	t_strc_gen	est;

	est.longa = ft_get_long_args(argc, argv);
	est.longb = 0;
	est.error = 0;
	est.aux = 3;
	est.count_mov = 0;
	est.a = ft_get_number(est.longa, argv, &est);
	est.longc = est.longa;
	return (est);
}

int	ft_check_error(t_strc_gen est, int argc, int x, int y)
{
	if (argc == 1)
		return (0);
	if (est.error != 0)
	{
		printf("\n\n %i", est.error);
		write(1, "Error1\n", 7);
		return (1);
	}
	while (x != est.longc)
	{
		if (est.a[x] == est.c[x])
			y++;
		x++;
	}
	if (y == est.longc)
		return (1);
	return (0);
}

/*void	leaks(void)
{
	system("leaks -q a.out");
}
*/
int	main(int argc, char **argv)
{
	t_strc_gen	est;
	int			x;
	int			y;

	x = 0;
	y = 0;
	est = ft_inicialize(argc, argv);
	est = ft_make_c(est, y);
	if (ft_check_error(est, argc, x, y) != 0)
		return (0);
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
	x = 0;
	while (x != est.longa)
	{
		printf(" - %i- ", est.a[x]);
		x++;
	}
	free(est.a);
	free(est.c);
	//atexit(leaks);
	return (0);
}