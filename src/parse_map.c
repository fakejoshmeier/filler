/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:33:48 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/06 18:44:50 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	parse_map(t_bodo board)
{
	char	*str;
	int		p_flag;

	p_flag = 0;
	while (get_next_line(&str, 1) > 0)
	{
		if (ft_strnstr(&str, "Plateau", 7))
			get_dimensions(&str, board);
		else if (ft_strnstr(&str, "Piece", 5))
		{
			get_piece(&str, board);
			p_flag = 1;
		}
		else if (p_flag == 0)
			check_map(&str, board);
		else if (p_flag == 1)
			get_token(&str, board);
	}
}

void	draw_map(t_bodo board)
