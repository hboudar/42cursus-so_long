/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:20:49 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/01 14:11:47 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *gm)
{
	gm->frame = 0;
	gm->win = mlx_new_window(gm->mlx,
			gm->a.width * 48, gm->a.height * 48, "so_long");
	if (!gm->win)
		on_destroy(gm, "Error: mlx_new_window failed\n", 0);
	gm->a.p[0] = mlx_xpm_file_to_image(gm->mlx, "textures/player.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.p[1] = mlx_xpm_file_to_image(gm->mlx, "textures/player_r.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.w = mlx_xpm_file_to_image(gm->mlx, "textures/wall.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.eo = mlx_xpm_file_to_image(gm->mlx, "textures/exit_o.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.ec = mlx_xpm_file_to_image(gm->mlx, "textures/exit_c.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.c = mlx_xpm_file_to_image(gm->mlx, "textures/c2.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.f = mlx_xpm_file_to_image(gm->mlx, "textures/floor.xpm",
			&gm->a.width, &gm->a.height);
	if (!gm->a.p[0] || !gm->a.p[1] || !gm->a.w
		|| !gm->a.eo || !gm->a.ec || !gm->a.c || !gm->a.f)
		on_destroy(gm, "Error: mlx_xpm_file_to_image failed\n", 1);
	ft_put_image(gm);
}

void	ft_put_image(t_game *gm)
{
	int	x;
	int	y;

	(1) && (x = 0, y = 0);
	mlx_clear_window(gm->mlx, gm->win);
	while (gm->mapf[x] != NULL)
	{
		if (gm->mapf[x][y] == '1')
			mlx_put_image_to_window(gm->mlx, gm->win, gm->a.w, y * 48, x * 48);
		else if (gm->mapf[x][y] == '0')
			mlx_put_image_to_window(gm->mlx, gm->win, gm->a.f, y * 48, x * 48);
		else if (gm->mapf[x][y] == 'E' && gm->c != 0)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->a.ec, y * 48, x * 48);
		else if (gm->mapf[x][y] == 'E' && gm->c == 0)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->a.eo, y * 48, x * 48);
		else if (gm->mapf[x][y] == 'C')
			mlx_put_image_to_window(gm->mlx, gm->win, gm->a.c, y * 48, x * 48);
		else if (gm->mapf[x][y] == 'P')
			mlx_put_image_to_window(gm->mlx, gm->win,
				gm->a.p[gm->frame], y * 48, x * 48);
		if (gm->mapf[x][y + 1] == '\0')
			(1) && (x++, y = 0);
		else
			y++;
	}
}
