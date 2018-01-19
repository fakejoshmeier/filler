/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:24:04 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/18 23:32:06 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

/*
** Piece validation takes a given point as its main parameters.  Everything else
** is just information that is incidental to given point.  It checks to see if
** the whole piece will fit in the given spot, length and widthwise, 
*/

int		piece_validation1(t_bodo *b, int r, int c)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (r + b->piece.row > b->row)
		return (0);
	if (c + b->piece.col > b->col)
		return (0);
	while (b->piece.wor[++i] && b->piece.loc[i])
	{
		if (b->map[b->piece.wor[i] + r][b->piece.loc[i] + c] != b->player ||
				b->player - 32 || '.')
			return (0);
		else if (b->map[b->piece.wor[i] + r][b->piece.loc[i] + c] ==
				b->player || b->player - 32)
			++j;
	}
	if (j == 1)
		return (1);
	return (0);
}

/*
 * Depending on either a flag, or a process, haven't decided yet, I'm going to
 * set off this validation process, designed to run when I've hit the other
 * player and am in position to spread my insidious reach other even farther
 * and devour the bastards whole.  Muahahahahahahahahahahahahahahahahahahahaha!
*/

I want to move diagonally!  Up and towards the corners!  To the parts less populated!
int		piece_validation2(t_bodo *b, int r, inc c)
{
	if (r + b->piece.row > b->row)
		return (0);
	if (c + b->piece.col > b->col)
		return (0);

}
