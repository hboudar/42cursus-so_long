/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:18:09 by hboudar           #+#    #+#             */
/*   Updated: 2024/03/28 15:20:35 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	is_playable(t_game *gm)
{
	int	x;
	int	y;
	int	yy;

	x = 0;
	y = 0;
	while (gm->map[x] != NULL)
	{
		if (gm->map[x][y + 1] == '\0')
		{
			x++;
			yy = y;
			y = 0;
		}
		else if (gm->map[x][y] == '1' || gm->map[x][y] == '0'
			|| gm->map[x][y] == '.' || gm->map[x][y] == '+'
			|| gm->map[x][y] == 'P' || gm->map[x][y] == 'N')
			y++;
		else
			on_destroy(gm, "Error: Map is not playable\n", 0);
	}
	(1) && (gm->a.width = yy + 1, gm->a.height = x);
	if (gm->a.width > 53 || gm->a.height > 29)
		on_destroy(gm, "Error: Map is too big\n", 0);
}

static void	flood_fill(t_game *gm, int x, int y)
{
	(gm->map[x][y] == 'E') && (gm->map[x][y] = '+');
	if (gm->map[x][y] == '1' || gm->map[x][y] == '.' || gm->map[x][y] == '+')
		return ;
	if (gm->map[x][y] == '0' || gm->map[x][y] == 'C' || gm->map[x][y] == 'N')
		gm->map[x][y] = '.';
	if (x > 0)
		flood_fill(gm, x - 1, y);
	if (y > 0)
		flood_fill(gm, x, y - 1);
	if (gm->map[x + 1] != NULL)
		flood_fill(gm, x + 1, y);
	if (gm->map[x][y + 1] != '\0')
		flood_fill(gm, x, y + 1);
}

static void	find_target(t_game *gm)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (gm->map[x][y])
	{
		if (gm->map[x][y] == 'P')
			break ;
		if (gm->map[x][y + 1] == '\0')
		{
			x++;
			y = 0;
		}
		if (gm->map[x][y + 1] != '\0')
			y++;
	}
	flood_fill(gm, x, y);
	is_playable(gm);
}

void	is_reachable(t_game *gm, char *file)
{
	char	*map;

	gm->fd = open(file, O_RDONLY);
	if (gm->fd == -1)
		on_destroy(gm, "Error: Map not found\n", 0);
	map = ft_strdup("");
	if (!map)
		on_destroy(gm, "Error: malloc failed\n", 0);
	gm->l = get_next_line(gm->fd);
	while (gm->l)
	{
		map = ft_strjoin(map, gm->l, 1);
		if (!map)
			on_destroy(gm, "Error: malloc failed\n", 0);
		gm->l = get_next_line(gm->fd);
	}
	gm->map = ft_split(map, '\n');
	gm->mapf = ft_split(map, '\n');
	if (!gm->map || !gm->mapf)
		on_destroy(gm, "Error: malloc failed\n", 0);
	free(map);
	find_target(gm);
}
