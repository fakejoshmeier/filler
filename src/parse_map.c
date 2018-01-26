/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:33:48 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/25 15:41:57 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_player(char *str, t_bodo *board)
{
	int		i;

	i = -1;
	while (str[++i] != 'p')
		;
	board->player = str[i + 1] == '1' ? 'o' : 'x';
	board->teki = board->player == 'o' ? 'x' : 'o';
	board->prog = 1;
	return ;
}

void	get_dimensions(char *str, t_bodo *board)
{
	board->row = ft_atoi(ft_strchr(str, ' '));
	board->col = ft_atoi(ft_strrchr(str, ' '));
	board->map = ft_memalloc((sizeof(char *) * board->row));
	board->prog = 2;
	board->pos = 0;
}

void	map_storage(char *str, t_bodo *board)
{
	str += 4;
	board->map[board->pos] = ft_memalloc(sizeof(char) * board->col);
	board->map[board->pos] = str;
	if (board->pos == board->row - 1)
	{
		board->prog = 3;
		return ;
	}
	board->pos += 1;
}

void	get_piece(char *str, t_bodo *board)
{
	board->piece = ft_memalloc(sizeof(t_piece));
	board->piece->row = ft_atoi(ft_strchr(str, ' '));
	board->piece->col = ft_atoi(ft_strrchr(str, ' '));
	board->piece->grid = ft_memalloc((sizeof(char *) * board->piece->row));
	board->prog = 4;
	board->pla = 0;
}

void	get_token(char *str, t_bodo *b)
{
	b->piece->grid[b->pla] = ft_memalloc((sizeof(char) * b->piece->col));
	b->piece->grid[b->pla] = str;
	if (b->pla == b->piece->row - 1)
	{
		b->prog = 5;
		return ;
	}
	b->pla += 1;
}
