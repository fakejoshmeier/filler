/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:25:53 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/17 15:56:00 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>
# include <stdio.h>

typedef struct	s_piece;
{
	int		row;
	int		col;
	int		*wor;
	int		*loc;
	char	**grid;
}				t_piece;

typedef struct	s_bodo
{
	int		row;
	int		col;
	int		prog;
	int		pos;
	int		pla;
	int		step;
	char	player;
	char	**map;
	char	**prev;
	t_piece	*piece;
}				t_bodo;

typedef struct	s_solv
{
	int		myco[2];
	int		opco[2];
	int		q1[2];
	int		q2[2];
	int		q3[2];
	int		q4[2];
	float	s1;
	int		s2;
	int		s3;
}				t_solv;

#endif
