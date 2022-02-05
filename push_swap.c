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

int	ft_atoi(const char *str, t_strc_gen *est)
{
	int	num;
	int	sign;
	int	cont;

	num = 0;
	sign = 1;
	cont = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (str[cont] >= '0' && str[cont] <= '9' && str[cont] != 0)
	{
		num = (num * 10) + (str[cont] - 48);
		cont++;
	}
	if (str[cont] != 0 || num < -2147483648 || num > 2147483647)
	{
		est->error = 1;
		return (0);
	}
	return (num * sign);
}

int *ft_get_number(int len, char **argv, t_strc_gen *est)
{
	int	*a;
	int aux;
	int	x;

	aux = 0;
	x = 0;
	a = malloc(sizeof(int) * len);
	while (x != len)
	{
		aux = ft_atoi(argv[x + 1], est);
		if (est->error != 0)
			return (0);
		a[x] = aux;
		printf(" <%i> ", a[x]);
		x++;
	}
	return (a);
}

struct s_strc ft_make_c(t_strc_gen est)
{
	int	x;
	int	aux;
	int	y;
	
	x = 0;
	y = 1;
	printf("\n1 llego\n");
	est.c = malloc(sizeof(int) * est.longa);
	while (x != est.longa)
	{
		est.c[x] = est.a[x];
		x++;
	}
	while (y != est.longa)
	{
		x = 0;
		y = 1;
		while (x + 1 != est.longa)
		{
			if (est.c[x] == est.c[x + 1])
			{
				est.error = 2;
				return (est);
			}
			if (est.c[x] > est.c[x + 1])
			{
				aux = est.c[x];
				est.c[x] = est.c[x + 1];
				est.c[x + 1] = aux;	
			}
			else 
				y++;
			x++;
		}
	}
	printf("\n2 llego\n");
	return (est);
}

/*void ft_clean_max(t_strc_gen est)
{
	//free(est.a);
	//free(est.b);
	//free(est.c);
}*/

int	main(int argc, char **argv)
{
	t_strc_gen	est;
	int			x;

	x = 0;
	est.longa = argc - 1;
	est.longb = 0;
	est.error = 0;
	est.aux = 3;
	est.count_mov = 0;
	est.a = ft_get_number(est.longa, argv, &est);
	est.longc = est.longa;
	printf("\nllego\n");
	if (est.error != 0)
	{
		printf("ERROR\n");
		return (0);
	}
	est = ft_make_c(est);
	est.mid = est.c[est.longa/2];
	printf("\n3 llego\n");
	printf("    .%i.  ", est.mid);
	if (est.error != 0)
	{
		printf("ERROR\n");
		return (0);
	}
	printf("\n4 llego\n");
	if (est.longa <= 3)
	{
		printf("\n3 o menos\n");
		est = ft_three(est);
	}
		
	else if (est.longa <= 100)
	{
		printf("\n100 o menos\n");
		est = ft_one_hun(est);
	}
		
	else
	{
		printf("ERROR\n");
		est = ft_five_hun(est);
		
	}
		
		
	x = 0;
	while (x != est.longa)
	{
		printf(" - %i- ", est.a[x]);
		x++;
	}
	//ft_clean_max(est);
	printf(" \nNUMERO DE MOVIMIENTOS- %i- \n", est.count_mov);
	return (0);
}
/*
int	main(void)
{
	int			x;
	t_strc_gen	estruc;
	x = 0;
	estruc.a = malloc (sizeof(int) * 6);
	estruc.b = malloc (sizeof(int) * 6);
	estruc.longa = 5;
	estruc.longb = 5;
	while (x != 5)
	{
		estruc.a[x] = x;
		estruc.b[x] = (x + 10);
		x++;
	}
	x = 0;
	while (x < 5)
	{
		printf(" <%i> ", estruc.a[x]);
		printf(" - %i - ", estruc.b[x]);
		x++;
	}
	estruc = ft_pass_b(estruc);
	x = 0;
	while (x < 4)
	{
		printf(" - %i- ", estruc.a[x]);
		x++;
	}
	x = 0;
	while (x < 6)
	{
		printf(" <%i> ", estruc.b[x]);
		x++;
	}
	return (0);
}
*/