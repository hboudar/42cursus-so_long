/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:31:27 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/01 08:51:08 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_player(t_game *gm, int mode)
{
	gm->v.xp = 0;
	gm->v.yp = 0;
	while (gm->mapf[gm->v.xp] != NULL)
	{
		if (gm->mapf[gm->v.xp][gm->v.yp + 1] == '\0')
		{
			gm->v.xp += 1;
			gm->v.yp = 0;
		}
		else if (gm->mapf[gm->v.xp][gm->v.yp] == 'P'
			|| gm->mapf[gm->v.xp][gm->v.yp] == ' ')
			break ;
		else
			gm->v.yp += 1;
	}
	if (!mode && gm->mapf[gm->v.xp][gm->v.yp] == ' ')
	{
		gm->v.xp = -1;
		gm->v.yp = -1;
	}
}

int	move_right(t_game *gm)
{
	if (gm->mapf[gm->v.xp][gm->v.yp + 1] == '0')
	{
		(1) && (gm->side = 0, two_frames(gm, 1));
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp][gm->v.yp + 1] = 'P');
	}
	else if (gm->mapf[gm->v.xp][gm->v.yp + 1] == 'C')
	{
		(1) && (gm->side = 0, two_frames(gm, 1), gm->c -= 1);
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp][gm->v.yp + 1] = 'P');
	}
	else if (gm->mapf[gm->v.xp][gm->v.yp + 1] == 'E' && gm->c == 0)
	{
		(1) && (gm->side = 0, two_frames(gm, 1));
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp][gm->v.yp + 1] = 'P');
		on_destroy(gm, "HAHAHAHAHAHAH\nyou win\n", 1);
	}
	else if (gm->mapf[gm->v.xp][gm->v.yp + 1] == 'N')
		on_destroy(gm, "HAHAHAHAHAHAH\nyou lost\n", 1);
	else
		return (1);
	return (0);
}

int	move_left(t_game *gm)
{
	if (gm->mapf[gm->v.xp][gm->v.yp - 1] == '0')
	{
		(1) && (gm->side = 1, two_frames(gm, 1));
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp][gm->v.yp - 1] = 'P');
	}
	else if (gm->mapf[gm->v.xp][gm->v.yp - 1] == 'C')
	{
		(1) && (gm->side = 1, two_frames(gm, 1), gm->c -= 1);
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp][gm->v.yp - 1] = 'P');
	}
	else if (gm->mapf[gm->v.xp][gm->v.yp - 1] == 'E' && gm->c == 0)
	{
		(1) && (gm->side = 1, two_frames(gm, 1));
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp][gm->v.yp - 1] = 'P');
		on_destroy(gm, "HAHAHAHAHAHAH\nyou win\n", 1);
	}
	else if (gm->mapf[gm->v.xp][gm->v.yp - 1] == 'N')
		on_destroy(gm, "HAHAHAHAHAHAH\nyou lost\n", 1);
	else
		return (1);
	return (0);
}

int	move_down(t_game *gm)
{
	if (gm->mapf[gm->v.xp + 1][gm->v.yp] == '0')
	{
		two_frames(gm, 1);
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp + 1][gm->v.yp] = 'P');
	}
	else if (gm->mapf[gm->v.xp + 1][gm->v.yp] == 'C')
	{
		(1) && (two_frames(gm, 1), gm->c -= 1);
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp + 1][gm->v.yp] = 'P');
	}
	else if (gm->mapf[gm->v.xp + 1][gm->v.yp] == 'E' && gm->c == 0)
	{
		two_frames(gm, 1);
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp + 1][gm->v.yp] = 'P');
		on_destroy(gm, "HAHAHAHAHAHAH\nyou win\n", 1);
	}
	else if (gm->mapf[gm->v.xp + 1][gm->v.yp] == 'N')
		on_destroy(gm, "HAHAHAHAHAHAH\nyou lost\n", 1);
	else
		return (1);
	return (0);
}

int	move_up(t_game *gm)
{
	if (gm->mapf[gm->v.xp - 1][gm->v.yp] == '0')
	{
		two_frames(gm, 1);
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp - 1][gm->v.yp] = 'P');
	}
	else if (gm->mapf[gm->v.xp - 1][gm->v.yp] == 'C')
	{
		(1) && (two_frames(gm, 1), gm->c -= 1);
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp - 1][gm->v.yp] = 'P');
	}
	else if (gm->mapf[gm->v.xp - 1][gm->v.yp] == 'E' && gm->c == 0)
	{
		two_frames(gm, 1);
		(1) && (gm->mapf[gm->v.xp][gm->v.yp] = '0',
			gm->mapf[gm->v.xp - 1][gm->v.yp] = 'P');
		on_destroy(gm, "HAHAHAHAHAHAH\nyou win\n", 1);
	}
	else if (gm->mapf[gm->v.xp - 1][gm->v.yp] == 'N')
		on_destroy(gm, "HAHAHAHAHAHAH\nyou lost\n", 1);
	else
		return (1);
	return (0);
}
