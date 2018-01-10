/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:33:48 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/09 23:22:04 by jmeier           ###   ########.fr       */
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
void	get_piece(char *str, t_bodo *board)
void	get_token(char *str, t_bodo *board)
void	map_storage(char *str, t_bodo *board)
