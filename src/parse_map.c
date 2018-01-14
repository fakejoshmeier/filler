/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:33:48 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/13 17:36:41 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_player(char *str, t_bodo *board)
{
	int		i;

	i = -1;
	while (str[++i] != 'p')
		;
	if (ft_isdigit(str[i]))
		{
			board->player = str[i] == 1 ? 'o' : 'x';
			return ;
		}
	else
		++i;
	}
}

void	get_dimensions(char *str, t_bodo *board)
{
	int		i;

	i = -1;
	str += 8;
	while (str[++i] != ' ')
		board->dimx = board->dimx * 10 + (str[i] - '0');
	while (str[++i] != ':')
		board->dimy = board->dimy * 10 + (str[i] - '0');
}

void	get_piece(char *str, t_bodo *board)
{
	int		i;

	i = -1;
	str += 6;
	while (str[++i] != ' ')
		board->piece.x = board->piece.x * 10 + (str[i] - '0');
	while (str[++i] != ':')
		board->piece.y = board->piece.y * 10 + (str[i] - '0');
}

void	get_token(char *str, t_bodo *board)
{
	board->piece.map[board->pla] = ft_memalloc(sizeof(char) * board->piece.y);
	if (board->pla <= board->piece.x)
		ft_strcpy(board->piece.grid[board->pla], str);
	if (board->pla == board->piece.x)
	{
		board->prog = 4;
		return ;
	}
	board->++pla;
}

void	map_storage(char *str, t_bodo *board)
{
	board->map[board->pos] = ft_memalloc(sizeof(char) * board->dimy);
	str += 4;
	if (board->pos <= board->dimx)
		ft_strcpy(map[board->pos], str);
	if (board->pos == board->dimx)
	{
		board->prog = 3;
		return ;
	}
	board->++pos;
}
