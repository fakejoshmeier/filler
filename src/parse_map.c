/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:33:48 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/10 18:18:27 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_player(char *str, t_bodo *board)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = str;
	while (tmp[++i])
	{
		if (ft_isdigit(tmp[i]))
		{
			board->player = tmp[i] == 1 ? 'x' : 'o';
			return ;
		}
	}
}

void	get_dimensions(char *str, t_bodo *board)
{
	str += 8;
	
}
void	get_piece(char *str, t_bodo *board)
void	get_token(char *str, t_bodo *board)
{
	board.piece->map[board->pla] = ft_memalloc(sizeof(char) * board.piece->y);
	if (board->pla <= board.piece->x)
		ft_strcpy(board.piece->grid[board->pla], str);
	if (board->pla == board.piece->x)
	{
		board->prog = 4;
		return ;
	}
	board->++pla;
}

void	map_storage(char *str, t_bodo *board)
{
	board->map[board->pos] = ft_memalloc(sizeof(char) * board->y);
	str += 4;
	if (board->pos <= board->x)
		ft_strcpy(map[board->pos], str);
	if (board->pos == board->x)
	{
		board->prog = 3;
		return ;
	}
	board->++pos;
}
