/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:20:52 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/01 13:49:25 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	two_frames(t_game *gm, int mode)
{
	if (mode == 1)
	{
		gm->nframe = 1;
		gm->frame = 1;
		ft_moves(gm, 0);
		mlx_do_sync(gm->mlx);
		gm->frame++;
		gm->nframe++;
	}
	else
	{
		gm->nframe = 1;
		ft_moves(gm, 0);
		mlx_do_sync(gm->mlx);
		gm->nframe++;
	}
	usleep(25000);
	ft_moves(gm, 0);
	return (0);
}

int	on_keypress(int key, t_game *gm, int i, int c)
{
	if (key != 124 && key != 123 && key != 125
		&& key != 126 && key != 53 && key != 49)
		return (0);
	(1) && (find_enemy(gm), find_player(gm, 1), gm->frame = 0, gm->nframe = 0);
	(key == 49) && (change_player(gm), gm->e = -1);
	(key == 53) && (on_destroy(gm, "Game closed\n", 1));
	(key == 124) && (c = move_right(gm));
	(key == 123) && (c = move_left(gm));
	(key == 126) && (c = move_up(gm));
	(key == 125) && (c = move_down(gm));
	(c == 0) && (c = -1, gm->m++, i = 1);
	while (c == -1 && ++i < 4)
	{
		(gm->v.yp >= gm->v.yn) && (gm->nside = 0);
		(gm->v.yp < gm->v.yn) && (gm->nside = 1);
		gm->frame = (gm->frame + 1) % 4;
		gm->nframe = (gm->nframe + 1) % 4;
		mlx_do_sync(gm->mlx);
		ft_moves(gm, 0);
		usleep(30000);
	}
	return (0);
}

int	enemy(t_game *gm, int i)
{
	static int	m = -1;
	int			c;

	(1) && (find_enemy(gm), find_player(gm, 0), i = 1, c = 1);
	if (gm->v.xp == -1 && gm->v.yp == -1)
	{
		go_to_exit(gm, 0, 0);
		return (0);
	}
	(m == 0 && gm->v.yp < gm->v.yn) && (c = move_left_n(gm));
	(m == 500 && gm->v.xp < gm->v.xn) && (c = move_up_n(gm));
	(m == 1000 && gm->v.xp > gm->v.xn) && (c = move_down_n(gm));
	(m == 1500 && gm->v.yp > gm->v.yn) && (c = move_right_n(gm));
	while (c == 0 && m % 500 == 0 && ++i < 4)
	{
		(i == 2) && (two_frames(gm, 2));
		gm->nframe = (gm->nframe + 1) % 4;
		(1) && (mlx_do_sync(gm->mlx), ft_moves(gm, 1), usleep(30000));
	}
	if (m > 1500)
		m = -1;
	m++;
	return (0);
}

int	main(int ac, char *av[])
{
	t_game	gm;

	if (ac != 2 || check_map(av[1], &gm, ft_strrchr(av[1], '.'), NULL))
		on_destroy(&gm, "Error: invalid arguments\n", 0);
	is_reachable(&gm, av[1]);
	gm.mlx = mlx_init();
	if (gm.mlx == NULL)
		on_destroy(&gm, "Error: mlx failed\n", 0);
	init_game(&gm);
	mlx_key_hook(gm.win, &on_keypress, &gm);
	mlx_hook(gm.win, 17, 0, &on_destroy, &gm);
	mlx_loop_hook(gm.mlx, &enemy, &gm);
	mlx_loop(gm.mlx);
	exit (0);
}
