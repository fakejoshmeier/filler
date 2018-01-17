/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_calc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:10:59 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/17 15:55:35 by jmeier           ###   ########.fr       */
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

/*
 * Just realized that this function does what I need with the addition of an
 * extra conditional statement.  It ostensibly will find the two points of
 * both players that are the closest on the map to each other.
 * With this data, I should be able to find out how to place the piece as I want
 * it.  That algo should rely on validation based on ugh.
*/
void	find_me_and_nme(t_bodo *board, t_solv *i)
{
	int		row;
	int		col;

	row = -1;
	col = -1;
	while (board->map[++row])
	{
		while (board->map[row][++col])
		{
			if (board->map[row][col] == 'x' || 'X')
				board->player == 'x' ? i->myco[0] = row && i->myco[1] = col :
					i->opco[0] = row && i->opco[1] = col;
			else if (board->map[row][col] == 'o' || 'O')
				board->player == 'o' ? i->myco[0] = row && i->myco[1] = col :
					i->opco[0] = row && i->opco[1] = col;
			if ((opco[0] || opco[1]) && (myco[0] || myco[1]))
				return;
		}
		col = -1;
	}
}

void	quadrants(t_bodo *board, t_solv *f)
{
	f->q1[1] = board->col % 2 == 0 ? (board->col / 2) - 1 :
		f->q1[1] = (board->col - 1) / 2;
	f->q2[1] = board->col - 1;
	f->q3[1] = board->col % 2 == 0 ? (board->col / 2) - 1 :
		f->q3[1] = (board->col - 1) / 2;
	f->q4[1] = board->col - 1;
	f->q1[0] = board->row % 2 == 0 ? (board->row / 2) - 1 :
		f->q1[0] = (board->row - 1) / 2;
	f->q2[0] = board->row % 2 == 0 ? (board->row / 2) - 1 :
		f->q2[0] = (board->row - 1) / 2;
	f->q3[0] = board->row - 1;
	f->q4[0] = board->row - 1;
}
