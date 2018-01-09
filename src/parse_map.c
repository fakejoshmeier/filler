/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:33:48 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/08 16:36:02 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	parse_map(t_bodo board)
{
	char	*str;
	int		pf;

	pf = 0;
	while (get_next_line(&str, 1) > 0)
	{
		if (ft_strstr(&str, "exec"))
		{

		}
		ft_strnstr(&str, "Plateau", 7) != 0 ? get_dimensions(&str, board) : 0;
		ft_strnstr(&str, "Piece", 5) != 0 ? get_piss(&str, board) && pf = 1 : 0;
		pf == 0 ? check_map(&str, board) : get_token(&str, board);
	}
}

void	draw_map(t_bodo board)
