/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:07:03 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/22 15:55:23 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

/*
** Functions for interpreting tokens.  this includes but is not limited to how
** many * there are in a token, the coordinates where a * can be found, and
** anything else I can think of that makes sense for me to know about token
*/

int		token_count(t_bodo *board)
{
	int		row;
	int		col;
	int		i;

	i = 0;
	row = 0;
	col = 0;
	while (row <= board->piece->row - 1 && board->piece->grid[row])
	{
		while (board->piece->grid[row][col])
		{
			if (board->piece->grid[row][col] == '*')
				++i;
			++col;
		}
		col = 0;
		row += 1;
	}
	return (i);
}

void	token_extract(t_bodo *board)
{
	int		row;
	int		col;
	int		i;

	i = token_count(board);
	row = 0;
	col = 0;
	board->piece->wor = ft_memalloc(sizeof(int) * i);
	board->piece->loc = ft_memalloc(sizeof(int) * i);
	i = 0;
	while (board->piece->grid[row] && row <= board->piece->row - 1)
	{
		while (board->piece->grid[row][col])
		{
			if (board->piece->grid[row][col] == '*')
			{
				board->piece->wor[i] = row;
				board->piece->loc[i] = col;
				++i;
			}
			++col;
		}
		col = 0;
		++row;
	}
}
