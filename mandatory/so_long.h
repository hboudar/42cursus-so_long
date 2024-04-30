/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:22:38 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/01 08:34:22 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libs/libft.h"

typedef struct s_assets
{
	int		width;
	int		height;
	void	*w;
	void	*p[2];
	void	*eo;
	void	*ec;
	void	*c;
	void	*f;
}	t_assets;

typedef struct s_game
{
	t_assets	a;
	void		*mlx;
	void		*win;
	char		**mapf;
	char		**map;
	char		*l;
	int			fd;
	int			frame;
	int			c;
	int			p;
	int			e;
	int			m;
}	t_game;

int		on_destroy(t_game *gm, char *msg, int mode);

int		check_map(char *map, t_game *game, char	*l, char *w);
void	is_reachable(t_game *gm, char *file);

void	init_game(t_game *gm);
void	ft_put_image(t_game *gm);

void	find_player(t_game *gm, int *x, int *y);
int		move_right(t_game *gm, int x, int y);
int		move_left(t_game *gm, int x, int y);
int		move_down(t_game *gm, int x, int y);
int		move_up(t_game *gm, int x, int y);

#endif
