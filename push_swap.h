/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <ade-blas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:11:07 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/24 18:07:20 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_strc
{
	int	*a;
	int	*b;
	int	*c;
	int	longa;
	int	longb;
	int	longc;
	int	aux;
	int	count_mov;
	int	error;
	int	mid;

}	t_strc_gen;

typedef struct s_num
{
	int	*a;
	int	num;
	int	aux;
	int	*auxy;
	int	x;
	int	y;
	int	z;
	int	countw;

}	t_num_gen;

t_strc_gen	ft_swap_a(t_strc_gen estruc);
t_strc_gen	ft_swap_b(t_strc_gen estruc);
t_strc_gen	ft_swap(t_strc_gen estruc);

t_strc_gen	ft_pass_a(t_strc_gen estruc);
t_strc_gen	ft_pass_b(t_strc_gen estruc);

t_strc_gen	ft_rot_a(t_strc_gen estruc);
t_strc_gen	ft_rot_b(t_strc_gen estruc);
t_strc_gen	ft_rot(t_strc_gen estruc);

t_strc_gen	ft_rrot_a(t_strc_gen estruc);
t_strc_gen	ft_rrot_b(t_strc_gen estruc);
t_strc_gen	ft_rrot(t_strc_gen estruc);

int			ft_get_less(t_strc_gen est, int *a);
int			ft_get_max(t_strc_gen est, int *a);
int			*ft_split(char *s, t_strc_gen est);
int			get_word(char *s, t_strc_gen *est);
int			ft_len(char *s);
int			ft_count_arg(char *argv);
int			ft_atoi(const char *str, t_strc_gen *est);
int			*ft_get_number(int longa, char **argv, t_strc_gen *est);

t_num_gen	ft_make_split(t_num_gen s_num, t_strc_gen est, char **argv);
t_num_gen	ft_inizialice(t_strc_gen *est, int longa);

t_strc_gen	ft_make_c(t_strc_gen est);
t_strc_gen	ft_three(t_strc_gen est);
t_strc_gen	ft_one_hun(t_strc_gen est);
t_strc_gen	ft_one_huntwo(t_strc_gen est);
t_strc_gen	ft_five_hun(t_strc_gen est);
t_strc_gen	ft_five_huntwo(t_strc_gen est, int i);
#endif