/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orient.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:54:11 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/19 21:27:21 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	nme_upleft(t_bodo *board, t_solv *info)
{
	int		r;
	int		c;

	r = info->opco[0];
	c = info->opco[1];
	while (board->map[r][c])
	{
		while (board->map[r][c])
		{
			if (piece_validation(board, r, c) == 1)
			{
				ft_printf("%d %d\n", r, c);
				return ;
			}
			++c;
		}
		c = 0;
		++r;
	}
}

void	nme_uprite(t_bodo *board, t_solv *info)
{
	int		r;
	int		c;

	r = info->opco[0];
	c = info->opco[1];
	while (board->map[r][c])
	{
		while (board->map[r][c] && c >= 0)
		{
			if (piece_validation(board, r, c) == 1)
			{
				ft_printf("%d %d\n", r, c);
				return ;
			}
			--c;
		}
		c = board->col;
		++r;
	}
}

void	nme_downleft(t_bodo *board, t_solv *info)
{
	int		r;
	int		c;

	r = info->opco[0];
	c = info->opco[1];
	while (board->map[r][c] && r >= 0)
	{
		while (board->map[r][c])
		{
			if (piece_validation(board, r, c) == 1)
			{
				ft_printf("%d %d\n", r, c);
				return ;
			}
			++c;
		}
		c = 0;
		--r;
	}
}

void	nme_downrite(t_bodo *board, t_solv *info)
{
	int		r;
	int		c;

	r = info->opco[0];
	c = info->opco[1];
	while (board->map[r][c] && r >= 0)
	{
		while (board->map[r][c] && c >= 0)
		{
			if (piece_validation(board, r, c) == 1)
			{
				ft_printf("%d %d\n", r, c);
				return ;
			}
			--c;
		}
		c = board->col;
		--r;
	}
}

void	orient_express(t_bodo *board, t_solv *info)
{
	if (touch)
	{
		if (info->up && info->left)
			nme_upleft(board, info);
		else if (info->up && !info->left)
			nme_uprite(board, info);
		else if (!info->up && info->left)
			nme_downleft(board, info);
		else
			nme_downrite(board, info);
	}
	else
		fill(board, info);
}
