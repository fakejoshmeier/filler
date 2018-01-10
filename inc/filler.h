/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:25:53 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/09 23:22:58 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libft.h>
# include <stdio.h>

typedef struct	s_piece;
{
	char	**grid;
	char	*x;
	char	*y;
}				t_piece;

typedef struct	s_bodo
{
	int		dimx;
	int		dimy;
	int		step;
	char	player;
	char	**map;
	char	**prev;
	t_piece	*piece;
}				t_bodo;


#endif
