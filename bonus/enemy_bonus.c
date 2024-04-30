/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:31:05 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/01 08:50:00 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_enemy(t_game *gm)
{
	gm->v.xn = 0;
	gm->v.yn = 0;
	while (gm->mapf[gm->v.xn] != NULL)
	{
		if (gm->mapf[gm->v.xn][gm->v.yn + 1] == '\0')
		{
			gm->v.xn += 1;
			gm->v.yn = 0;
		}
		else if (gm->mapf[gm->v.xn][gm->v.yn] == 'N')
			return ;
		else
			gm->v.yn += 1;
	}
}

int	move_right_n(t_game *gm)
{
	if (gm->mapf[gm->v.xn][gm->v.yn + 1] == '0')
	{
		two_frames(gm, 2);
		gm->mapf[gm->v.xn][gm->v.yn] = '0';
		gm->mapf[gm->v.xn][gm->v.yn + 1] = 'N';
	}
	else if (gm->mapf[gm->v.xn][gm->v.yn + 1] == 'P')
		on_destroy(gm, "HAHAHAHAHAHAHAH\nyou lost\n", 1);
	return (0);
}

int	move_left_n(t_game *gm)
{
	if (gm->mapf[gm->v.xn][gm->v.yn - 1] == '0')
	{
		two_frames(gm, 2);
		gm->mapf[gm->v.xn][gm->v.yn] = '0';
		gm->mapf[gm->v.xn][gm->v.yn - 1] = 'N';
	}
	else if (gm->mapf[gm->v.xn][gm->v.yn - 1] == 'P')
		on_destroy(gm, "HAHAHAHAHAHAHAH\nyou lost\n", 1);
	return (0);
}

int	move_up_n(t_game *gm)
{
	if (gm->mapf[gm->v.xn - 1][gm->v.yn] == '0')
	{
		two_frames(gm, 2);
		gm->mapf[gm->v.xn][gm->v.yn] = '0';
		gm->mapf[gm->v.xn - 1][gm->v.yn] = 'N';
	}
	else if (gm->mapf[gm->v.xn - 1][gm->v.yn] == 'P')
		on_destroy(gm, "HAHAHAHAHAHAHAH\nyou lost\n", 1);
	return (0);
}

int	move_down_n(t_game *gm)
{
	if (gm->mapf[gm->v.xn + 1][gm->v.yn] == '0')
	{
		two_frames(gm, 2);
		gm->mapf[gm->v.xn][gm->v.yn] = '0';
		gm->mapf[gm->v.xn + 1][gm->v.yn] = 'N';
	}
	else if (gm->mapf[gm->v.xn + 1][gm->v.yn] == 'P')
		on_destroy(gm, "HAHAHAHAHAHAHAH\nyou lost\n", 1);
	return (0);
}
