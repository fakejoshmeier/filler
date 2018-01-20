/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:25:53 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/19 22:18:56 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <ft_printf.h>
# include <stdio.h>
# define ESCAPE(a) if (a) return ;

typedef struct	s_piece
{
	int			row;
	int			col;
	int			*wor;
	int			*loc;
	char		**grid;
}				t_piece;

typedef struct	s_bodo
{
	int			row;
	int			col;
	int			prog;
	int			pos;
	int			pla;
	int			step;
	char		player;
	char		**map;
	char		**prev;
	t_piece		*piece;
}				t_bodo;

typedef struct	s_solv
{
	int		myco[2];
	int		opco[2];
	int		q1[2];
	int		q2[2];
	int		q3[2];
	int		q4[2];
	int		up;
	int		left;
}				t_solv;

int				main(void);
void			swooce(char *str, t_bodo *board, t_solv *info);
void			get_player(char *str, t_bodo *board);
void			get_dimensions(char *str, t_bodo *board);
void			map_storage(char *str, t_bodo *board);
void			get_piece(char *str, t_bodo *board);
void			get_token(char *str, t_bodo *board);
void			orient_express(t_bodo *board, t_solv *info);
void			nme_upleft(t_bodo *board, t_solv *info);
void			nme_uprite(t_bodo *board, t_solv *info);
void			nme_downleft(t_bodo *board, t_solv *info);
void			nme_downrite(t_bodo *board, t_solv *info);
void			hot_garbage(t_bodo *board, t_solv *i, int row, int col);
void			pure_trash(t_bodo *board, t_solv *i, int row, int col);
void			quadrants(t_bodo *board, t_solv *f);
void			find_me_nme_ori(t_bodo *board, t_solv *i);
void			token_extract(t_bodo *board);
int				token_count(t_bodo *board);
int				piece_validation(t_bodo *b, int r, int c);

#endif
