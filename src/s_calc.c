/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_calc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:10:59 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/16 00:39:48 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

/*
** I plan to use a somewhat funky strategy.  This program, and any others in the
** s_calc series if they become needed later on, will pertain to all the
** mathematical calculations I need to solve the placement of pieces.  My
** strategy is twofold.  I want to make an extremely aggressive algorithm, so
** the first step is to rush the other player's pieces.  Once I first am as
** close to the other player, the strategy changes.  The idea becomes to make a
** wall, but rather than spread out in a shape similar to a 'T', I am hoping for
** more of a 'Y' shape, ideally to corral the other player even more.  This part
** of the algo will rely on parsing the map into quadrants, and then shooting
** forwards to walls along an appropriate slope that limits the opponent to less
** than half the board, after which I fill in all the blank spaces I can.
*/

void	find_init_co_m(t_bodo *board, t_solv *i)
{
	int		sink;
	int		run;

	sink = 0;
	run = -1;
	while (board->map[++sink])
	{
		while (board->map[sink][++run])
		{
			if (board->map[sink][run] == 'x' || 'X')
				board->player == 'x' ? i->myco[0] = sink && i->myco[1] = run :
					i->opco[0] = sink && i->opco[1] = run;
			else if (board->map[sink][run] == 'o' || 'O')
				board->player == 'o' ? i->myco[0] = sink && i->myco[1] = run :
					i->opco[0] = sink && i->opco[1] = run;
		}
	}
	i->s1 = (myco[1] - opco[1]) / (myco[0] - myco[0]);
}

void	quadrants(t_bodo *board, t_solv *f)
{
	f->q1[0] = board->dimy % 2 == 0 ? (board->dimy / 2) - 1 :
		f->q1[0] = (board->dimy - 1) / 2;
	f->q2[0] = board->dimy - 1;
	f->q3[0] = board->dimy % 2 == 0 ? (board->dimy / 2) - 1 :
		f->q3[0] = (board->dimy - 1) / 2;
	f->q4[0] = board->dimy - 1;
	f->q1[1] = board->dimx % 2 == 0 ? (board->dimx / 2) - 1 :
		f->q1[1] = (board->dimx - 1) / 2;
	f->q2[1] = board->dimx % 2 == 0 ? (board->dimx / 2) - 1 :
		f->q2[1] = (board->dimx - 1) / 2;
	f->q3[1] = board->dimx - 1;
	f->q4[1] = board->dimx - 1;
}
