/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orient.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:54:11 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/26 17:18:51 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		nme_upleft(t_bodo *board)
{
	int		r;
	int		c;

	r = 0;
	c = 0;
	while (r < board->row)
	{
		while (c < board->col)
		{
			if (piece_validation(board, r, c))
			{
				ft_printf("%d %d\n", r, c);
				return (1);
			}
			c++;
		}
		r++;
		c = 0;
	}
	return (0);
}

int		nme_uprite(t_bodo *board)
{
	int		r;
	int		c;

	r = 0;
	c = board->col - 1;
	while (r < board->row)
	{
		while (c >= 0)
		{
			if (piece_validation(board, r, c) == 1)
			{
				ft_printf("%d %d\n", r, c);
				return (1);
			}
			c--;
		}
		c = (board->col - 1);
		r++;
	}
	return (0);
}

int		nme_downleft(t_bodo *board)
{
	int		r;
	int		c;

	r = board->row - 1;
	c = 0;
	while (r >= 0)
	{
		while (c < board->col)
		{
			if (piece_validation(board, r, c) == 1)
			{
				ft_printf("%d %d\n", r, c);
				return (1);
			}
			c++;
		}
		c = 0;
		r--;
	}
	return (0);
}

int		nme_downrite(t_bodo *board)
{
	int		r;
	int		c;

	r = board->row - 1;
	c = board->col - 1;
	while (r >= 0)
	{
		while (c >= 0)
		{
			if (piece_validation(board, r, c))
			{
				ft_printf("%d %d\n", r, c);
				return (1);
			}
			c--;
		}
		c = (board->col - 1);
		r--;
	}
	return (0);
}

int		orient_express(t_bodo *board, t_solv *info)
{
	int		i;

	i = 0;
	if (info->up && info->left)
		i = nme_upleft(board);
	else if (info->up && info->left == 0)
		i = nme_uprite(board);
	else if (info->up == 0 && info->left)
		i = nme_downleft(board);
	else if (info->up == 0 && info->left == 0)
		i = nme_downrite(board);
	if (i == 0)
		ft_printf("0 0\n");
	return (i);
}
