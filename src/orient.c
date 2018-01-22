/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orient.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:54:11 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/22 00:53:40 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	nme_upleft(t_bodo *board, t_solv *info)
{
	int		r;
	int		c;

	r = info->opco[0];
	c = info->opco[1];
	while (board->map[r++][c])
	{
		while (board->map[r][c++])
		{
			if (piece_validation(board, r, c))
			{
				ft_printf("%d %d\n", r, c);
				return ;
			}
		}
		c = 0;
	}
}

void	nme_uprite(t_bodo *board, t_solv *info)
{
	int		r;
	int		c;

	r = info->opco[0];
	c = info->opco[1];
	while (board->map[r++][c])
	{
		while (board->map[r][c--] && c >= 0)
		{
			if (piece_validation(board, r, c) == 1)
			{
				ft_printf("%d %d\n", r, c);
				return ;
			}
		}
		c = (board->col);
	}
}

void	nme_downleft(t_bodo *board, t_solv *info)
{
	int		r;
	int		c;

	r = info->opco[0];
	c = info->opco[1];
	while (board->map[r--][c] && r >= 0)
	{
		while (board->map[r][c++])
		{
			if (piece_validation(board, r, c) == 1)
			{
				ft_printf("%d %d\n", r, c);
				return ;
			}
		}
		c = 0;
	}
}

void	nme_downrite(t_bodo *board, t_solv *info)
{
	int		r;
	int		c;

	r = info->opco[0];
	c = info->opco[1];
	ft_printf("%i %i\n", r, c);
	while (board->map[r--][c] && r >= 0)
	{
		while (board->map[r][c--] && c >= 0)
		{
			ft_printf("%d %d\n", r, c);
			if (piece_validation(board, r, c) == 1)
			{
				ft_printf("**************%d %d\n", r, c);
				return ;
			}
		}
		c = (board->col);
	}
	ft_printf("noworky\n");
}

void	orient_express(t_bodo *board, t_solv *info)
{
	if (info->up && info->left)
	{
		ft_printf("up&left\n");
		nme_upleft(board, info);
	}
	else if (info->up && info->left == 0)
	{
		ft_printf("up&rite\n");
		nme_uprite(board, info);
	}
	else if (info->up == 0 && info->left)
	{
		ft_printf("down&left\n");
		nme_downleft(board, info);
	}
	else if (info->up == 0 && info->left == 0)
	{
		ft_printf("down&rite\n");
		nme_downrite(board, info);
	}
}
