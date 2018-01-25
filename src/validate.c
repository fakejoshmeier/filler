/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:24:04 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/24 18:24:40 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

/*
** Piece validation takes a given point as its main parameters.  Everything else
** is just information that is incidental to given point.  It checks to see if
** the whole piece will fit in the given spot, length and widthwise, If I give
** this a little bit of thought, I only need one validation function in and of
** itself.  All this function does is check for if a spot works or not.  I need
** to write something that will choose spots to input though.  Back to the
** Orient!
*/

int		piece_validation(t_bodo *b, int r, int c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (r + b->piece->row > b->row)
		return (0);
	else if (c + b->piece->col > b->col)
		return (0);
	while (i <= token_count(b))
	{
		if (b->map[r + b->piece->wor[i]][c + b->piece->loc[i]] == b->player
			|| b->map[b->piece->wor[i] + r][b->piece->loc[i] + c] ==
			b->player - 32)
			++j;
		else if (b->map[b->piece->wor[i] + r][b->piece->loc[i] + c] !=
			b->player && b->map[b->piece->wor[i] + r][b->piece->loc[i] + c] !=
			b->player - 32 && b->map[b->piece->wor[i] + r][b->piece->loc[i] + c]
			!= '.')
			return (0);
		i++;
	}
	if (j == 1)
		return (1);
	return (0);
}
