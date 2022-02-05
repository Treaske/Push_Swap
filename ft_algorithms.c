/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:57:26 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/24 18:08:56 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_strc	ft_three(t_strc_gen est)
{
	if (est.a[1] == est.c[0])
	{
		if (est.a[2] == est.c[est.longa - 1])
			ft_swap_a(est);
		else
			ft_rot_a(est);
	}
	else if (est.a[1] == est.c[est.longa - 1])
	{
		if (est.a[0] == est.c[0])
		{
			ft_swap_a(est);
			ft_rot_a(est);
		}
		else
			ft_rrot_a(est);
	}
	else
	{
		ft_swap_a(est);
		ft_rrot_a(est);
	}
	return (est);
}

int	ft_check_lower(t_strc_gen est)
{
	int	x;

	x = 0;
	while (x < est.longa)
	{
		if (est.a[x] <= est.mid)
		{
			return (1);
		}
		x++;
	}
	return (0);
}

int	ft_get_count(t_strc_gen *est)
{
	int	count;
	int	x;

	x = 0;
	count = 0;
	//if(est->b[count] != est->c[est->longc - est->aux])
	//printf("\n  NUMERO DE B : %i\n", est->b[count]);
	//printf("\n  NUMERO A BUSCAR  : %i\n", est->c[est->longc - est->aux]);

	while (est->b[count] != est->c[est->longc - est->aux])
		count++;
	if (count < (est->longb/2))
		return (1); 
	//si es menos de la mitad de la longitud lo mejor es rot_b
	return (2);
}

struct s_strc	ft_one_hun(t_strc_gen est)
{
	int	x;
	int	aux;

	x = 2;
	aux = 0;
	while (est.longa != 2)
	{
		if (est.longa % 2 == 0)
			aux += (est.longa / 2) - 1;
		else
			aux += (est.longa / 2);
		est.mid = est.c[aux];
		while (ft_check_lower(est) != 0 && est.longa != 2)
		{
			if (est.a[0] <= est.mid)
			{
				est = ft_pass_a(est);
			}
			else
			{
				est = ft_rot_a(est);
			}
			
		}
		
	}
	getchar();
	printf(" \nORDENAMOS LOS QUE QUEDAN ");
	/* ORDENAR LOS DOS QUE SE QUEDAN */
		if (est.a[0] > est.a[1])
			est = ft_swap_a(est);
	/* IR METIENDO UNO A UNO, OBSERVANDO SI SALE MEJOR HACER RRA O RA HASTA LLEGAR AL NUMERO*/
	
	printf(" \nMETEMOS EN A");
	while (est.longa != est.longc)
	{
		if (ft_get_count(&est) == 1)
		{
			if (est.b[0] != est.c[est.longc - est.aux])
			{
				while (est.b[0] != est.c[est.longc - est.aux])
					est = ft_rot_b(est);
			}
		}
		else
		{
			if (est.b[0] != est.c[est.longc - est.aux])
			{
				while (est.b[0] != est.c[est.longc - est.aux])
					est = ft_rrot_b(est);
			}
		}
		est.aux++;
		est = ft_pass_b(est);
		//getchar();
	}
	return (est);
		
}

/*int	ft_long_binary(t_strc_gen est)
{
}
*/
struct s_strc	ft_five_hun(t_strc_gen est)
{
	/*
		1- pasar los numeros ordenados de c á a pero con numeros seguidos (para evitar negativos)
		2- sacar la longitud en bytes  del numero mayor para saber las iteraciones a realizar
		3- realizar bucle en cada cifra de binario que recorra todo a y pase a b los 0
		4- devolver los de b á a y repetir 3-
	*/

	//reasignar los numeros

	int	x;
	int	j;
	int	y;
	int i;

	i = 0;
	x = 0;
	y = 0;
	j = 0;
	
	while (x != est.longc)
	{
		j = 0;
		while (est.a[x] != est.c[j])
			j++;
		est.a[x] = j;
		x++;
	}

	// reasignar los numeros

	// sacar la longitud en bytes

	// x = ft_long_binary(est);
	while((est.c[est.longc - 1] >> i) != 0)
	{
		i++;
	}
	//i++;
	// sacar la longitud en bytes

	// bucle que pasa los 0 a b

	j = 0;
	while (j != i)
	{
		y = 0;
		while (y < est.longc)
		{
			if (((est.a[0] >> j) & 1) == 0)
				est = ft_pass_a(est);
			else
				est = ft_rot_a(est);
			y++;
		}
		// volver a pasar á a
		y = est.longb;
		while (y != 0)
		{	
			est = ft_pass_b(est);
			y--;
			
		}
		j++;
	}
	//reasignar
	x = 0;
	while (x != est.longc)
	{
		est.a[x] = est.c[x];
		x++;
	}
	return (est);
}