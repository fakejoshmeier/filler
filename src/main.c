/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:09:04 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/26 18:40:12 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

/*
** Suite is a loop that runs through all that nonsense.  Need to find a way to
** run through this
** prog0 - loop begins;
** prog1 - player char is found.  Prog1 needs to be tripped only once
** prog2 - size of map is found, values stored in board->dimx, board->dimy.
** Do they really need to though?  Just set them as reg ints for size of grid
** later.  Geh, figure it
** 	map gets stored into board->map.  Thing checks for whether prev has
** 	anything in it.  If yes, run as it should, if not, it runs as it does for
** 	the first time.
** 	prog3 - piece is read and stored.
** 	prog4 - piece is added into map, stored new map is stored in prev, and map
** 	is wiped. Prog gets set back to 2 until loop dies
*/

void	swooce(char *str, t_bodo *board)
{
	if (ft_strstr(str, "exec") && board->prog == 0)
		get_player(str, board);
	else if (ft_strstr(str, "Plateau"))
		get_dimensions(str, board);
	else if (ft_strstr(str, "12345"))
		return ;
	else if (!ft_strstr(str, "012345") && board->prog == 2)
		map_storage(str, board);
	if (board->prog == 4)
		get_token(str, board);
	else if (ft_strstr(str, "Piece"))
		get_piece(str, board);
}

int		main(void)
{
	t_bodo	*board;
	t_solv	*info;
	char	*str;

	board = ft_memalloc(sizeof(t_bodo));
	info = ft_memalloc(sizeof(t_solv));
	while (board->prog < 6)
	{
		get_next_line(0, &str);
		swooce(str, board);
		if (board->prog == 5)
		{
			token_extract(board);
			find_me_nme_ori(board, info);
			if (orient_express(board, info) == 0)
				board->prog = 6;
		}
	}
	free(board);
	free(info);
	free(str);
	sleep(1);
	return (0);
}
