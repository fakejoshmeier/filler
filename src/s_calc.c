/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_calc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:10:59 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/25 17:34:11 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	hot_garbage(t_solv *i, int row, int col, int x)
{
	if (x == 1)
	{
		i->opco[0] = row;
		i->opco[1] = col;
	}
	else if (x == 0)
	{
		i->myco[0] = row;
		i->myco[1] = col;
	}
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
			if (board->map[row][col] == board->teki || board->map[row][col] ==
				board->teki - 32)
				hot_garbage(i, row, col, 1);
			else if (board->map[row][col] == board->player ||
				board->map[row][col] == board->player - 32)
				hot_garbage(i, row, col, 0);
			if ((i->opco[0] || i->opco[1]) && (i->myco[0] || i->myco[1]))
			{
				i->up = i->opco[0] <= i->myco[0] ? 1 : 0;
				i->left = i->opco[1] <= i->myco[1] ? 1 : 0;
				return ;
			}
		}
		col = -1;
	}
}
