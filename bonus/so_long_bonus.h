/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:22:38 by hboudar           #+#    #+#             */
/*   Updated: 2024/03/30 15:18:52 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libs/libft.h"

typedef struct s_vector
{
	int	xp;
	int	yp;
	int	xn;
	int	yn;
	int	xe;
	int	ye;
}	t_vector;

typedef struct s_assets
{
	int		width;
	int		height;
	void	*w;
	void	*p[2][4];
	void	*n[4][4];
	void	*sp;
	void	*eo;
	void	*ec;
	void	*c;
	void	*f;
}	t_assets;

typedef struct s_game
{
	t_assets	a;
	t_vector	v;
	char		**mapf;
	char		**map;
	char		*move;
	char		*l;
	void		*mlx;
	void		*win;
	int			fd;
	int			frame;
	int			side;
	int			nframe;
	int			nside;
	int			c;
	int			p;
	int			e;
	int			n;
	int			m;
}	t_game;

int		on_destroy(t_game *gm, char *str, int mode);

int		check_map(char *map, t_game *game, char	*l, char *w);
void	is_reachable(t_game *gm, char *file);

void	init_game(t_game *gm);
void	ft_put_image(t_game *gm, int x, int y);
int		two_frames(t_game *gm, int mode);
void	ft_moves(t_game *gm, int mode);

void	find_player(t_game *gm, int mode);
int		move_right(t_game *gm);
int		move_left(t_game *gm);
int		move_down(t_game *gm);
int		move_up(t_game *gm);

void	find_enemy(t_game *gm);
int		move_right_n(t_game *gm);
int		move_left_n(t_game *gm);
int		move_up_n(t_game *gm);
int		move_down_n(t_game *gm);

int		change_player(t_game *gm);
int		enemy(t_game *gm, int i);
void	go_to_exit(t_game *gm, int i, int c);

#endif
