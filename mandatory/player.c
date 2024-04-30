/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:31:27 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/01 14:12:00 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *gm, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (gm->mapf[*x] != NULL)
	{
		if (gm->mapf[*x][*y + 1] == '\0')
		{
			*x += 1;
			*y = 0;
		}
		else if (gm->mapf[*x][*y] == 'P')
			return ;
		else
			*y += 1;
	}
}

int	move_right(t_game *gm, int x, int y)
{
	gm->frame = 0;
	if (gm->mapf[x][y + 1] == '0')
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x][y + 1] = 'P';
	}
	else if (gm->mapf[x][y + 1] == 'C')
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x][y + 1] = 'P';
		gm->c -= 1;
	}
	else if (gm->mapf[x][y + 1] == 'E' && gm->c == 0)
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x][y + 1] = 'P';
		on_destroy(gm, "You win", 1);
	}
	else
		return (1);
	return (0);
}

int	move_left(t_game *gm, int x, int y)
{
	gm->frame = 1;
	if (gm->mapf[x][y - 1] == '0')
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x][y - 1] = 'P';
	}
	else if (gm->mapf[x][y - 1] == 'C')
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x][y - 1] = 'P';
		gm->c -= 1;
	}
	else if (gm->mapf[x][y - 1] == 'E' && gm->c == 0)
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x][y - 1] = 'P';
		on_destroy(gm, "You win", 1);
	}
	else
		return (1);
	return (0);
}

int	move_up(t_game *gm, int x, int y)
{
	if (gm->mapf[x - 1][y] == '0')
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x - 1][y] = 'P';
	}
	else if (gm->mapf[x - 1][y] == 'C')
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x - 1][y] = 'P';
		gm->c -= 1;
	}
	else if (gm->mapf[x - 1][y] == 'E' && gm->c == 0)
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x - 1][y] = 'P';
		on_destroy(gm, "You win", 1);
	}
	else
		return (1);
	return (0);
}

int	move_down(t_game *gm, int x, int y)
{
	if (gm->mapf[x + 1][y] == '0')
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x + 1][y] = 'P';
	}
	else if (gm->mapf[x + 1][y] == 'C')
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x + 1][y] = 'P';
		gm->c -= 1;
	}
	else if (gm->mapf[x + 1][y] == 'E' && gm->c == 0)
	{
		gm->mapf[x][y] = '0';
		gm->mapf[x + 1][y] = 'P';
		on_destroy(gm, "You win", 1);
	}
	else
		return (1);
	return (0);
}
