/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_calc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:10:59 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/22 00:20:40 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	hot_garbage(t_bodo *board, t_solv *i, int row, int col)
{
	if (board->player == 'x')
	{
		i->myco[0] = row;
		i->myco[1] = col;
	}
	else
	{
		i->opco[0] = row;
		i->opco[1] = col;
	}
}

void	pure_trash(t_bodo *board, t_solv *i, int row, int col)
{
	if (board->player == 'o')
	{
		i->myco[0] = row;
		i->myco[1] = col;
	}
	else
	{
		i->opco[0] = row;
		i->opco[1] = col;
	}
}

void	quadrants(t_bodo *board, t_solv *f)
{
	f->q1[1] = board->col % 2 == 0 ? ((board->col / 2) - 1) :
		(board->col - 1) / 2;
	f->q2[1] = board->col - 1;
	f->q3[1] = board->col % 2 == 0 ? (board->col / 2) - 1 :
		(board->col - 1) / 2;
	f->q4[1] = board->col - 1;
	f->q1[0] = board->row % 2 == 0 ? (board->row / 2) - 1 :
		(board->row - 1) / 2;
	f->q2[0] = board->row % 2 == 0 ? (board->row / 2) - 1 :
		(board->row - 1) / 2;
	f->q3[0] = board->row - 1;
	f->q4[0] = board->row - 1;
}

void	find_me_nme_ori(t_bodo *board, t_solv *i)
{
	int		row;
	int		col;

	row = -1;
	col = -1;
	while (board->map[++row])
	{
		while (board->map[row][++col])
		{
			if (board->map[row][col] == 'x' || board->map[row][col] == 'X')
				hot_garbage(board, i, row, col);
			else if (board->map[row][col] == 'o' || board->map[row][col] == 'O')
				pure_trash(board, i, row, col);
			if ((i->opco[0] || i->opco[1]) && (i->myco[0] || i->myco[1]))
			{
				i->up = i->opco[0] < i->myco[0] ? 1 : 0;
				i->left = i->opco[1] < i->myco[1] ? 1 : 0;
				quadrants(board, i);
				return ;
			}
		}
		col = -1;
	}
}
