/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:25:53 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/10 17:40:01 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>
# include <stdio.h>

typedef struct	s_piece;
{
	int		x;
	int		y;
	char	**grid;
}				t_piece;

typedef struct	s_bodo
{
	int		dimx;
	int		dimy;
	int		prog;
	int		pos;
	int		pla;
	char	player;
	char	**map;
	char	**prev;
	t_piece	*piece;
}				t_bodo;

#endif
