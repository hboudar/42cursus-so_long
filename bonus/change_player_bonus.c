/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:47:21 by hboudar           #+#    #+#             */
/*   Updated: 2024/03/30 17:49:57 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	change_player(t_game *gm)
{
	find_player(gm, 1);
	if (gm->mapf[gm->v.xp][gm->v.yp] == 'P')
	{
		gm->mapf[gm->v.xp][gm->v.yp] = ' ';
		gm->p = 0;
	}
	else if (gm->mapf[gm->v.xp][gm->v.yp] == ' ')
	{
		gm->mapf[gm->v.xp][gm->v.yp] = 'P';
		gm->p = 1;
	}
	return (0);
}

static int	if_close_to_exit(t_game *gm)
{
	if (gm->v.xe == gm->v.xn && (gm->v.ye + 1 == gm->v.yn
			|| gm->v.ye - 1 == gm->v.yn))
		return (1);
	else if (gm->v.ye == gm->v.yn && (gm->v.xe + 1 == gm->v.xn
			|| gm->v.xe - 1 == gm->v.xn))
		return (1);
	return (0);
}

static void	find_exit(t_game *gm)
{
	gm->v.xe = 0;
	gm->v.ye = 0;
	while (gm->mapf[gm->v.xe] != NULL)
	{
		if (gm->mapf[gm->v.xe][gm->v.ye + 1] == '\0')
		{
			gm->v.xe += 1;
			gm->v.ye = 0;
		}
		else if (gm->mapf[gm->v.xe][gm->v.ye] == 'E')
			return ;
		else
			gm->v.ye += 1;
	}
}

void	go_to_exit(t_game *gm, int i, int c)
{
	static int	e = -1;

	(1) && (find_enemy(gm), find_exit(gm), c = -1, e++);
	if (if_close_to_exit(gm))
	{
		gm->nside = (gm->nside == 0) * 1;
		if (e == 3000)
			ft_moves(gm, 0);
	}
	else
	{
		(e == 0 && gm->v.ye > gm->v.yn) && (c = move_right_n(gm));
		(e == 1000 && gm->v.ye < gm->v.yn) && (c = move_left_n(gm));
		(e == 2000 && gm->v.xe < gm->v.xn) && (c = move_up_n(gm));
		(e == 3000 && gm->v.xe > gm->v.xn) && (c = move_down_n(gm));
		while (c == 0 && ++i < 4)
		{
			(i == 2) && (two_frames(gm, 2));
			gm->nframe = (gm->nframe + 1) % 4;
			(1) && (mlx_do_sync(gm->mlx), ft_moves(gm, 0), usleep(30000));
		}
	}
	if (e >= 3000)
		e = -1;
}
