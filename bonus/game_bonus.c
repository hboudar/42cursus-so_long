/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:20:49 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/01 08:50:51 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_moves(t_game *gm, int mode)
{
	char	*tmp;
	char	*tmp2;

	if (mode)
	{
		(1) && (find_player(gm, 1), find_enemy(gm), gm->p = 1);
		(gm->v.yp <= gm->v.yn) && (gm->nside = 3);
		(gm->v.yp > gm->v.yn) && (gm->nside = 2);
	}
	tmp = ft_strdup("Moves : ");
	if (!tmp)
		on_destroy(gm, "Error: ft_strdup failed\n", 1);
	tmp2 = ft_itoa(gm->m);
	if (!tmp2)
		on_destroy(gm, "Error: ft_itoa failed\n", 1);
	gm->move = ft_strjoin(tmp, tmp2, 0);
	if (!gm->move)
		on_destroy(gm, "Error: ft_strjoin failed\n", 1);
	ft_put_image(gm, 0, 0);
	free(tmp);
	free(tmp2);
	free(gm->move);
}

static void	init_enemy(t_game *gm)
{
	gm->a.n[1][0] = mlx_xpm_file_to_image(gm->mlx, "textures/enemyr.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[1][1] = mlx_xpm_file_to_image(gm->mlx, "textures/enemyr1.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[1][2] = mlx_xpm_file_to_image(gm->mlx, "textures/enemyr2.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[1][3] = mlx_xpm_file_to_image(gm->mlx, "textures/enemyr3.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[2][0] = mlx_xpm_file_to_image(gm->mlx, "textures/enemy.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[2][1] = mlx_xpm_file_to_image(gm->mlx, "textures/em1.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[2][2] = mlx_xpm_file_to_image(gm->mlx, "textures/em2.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[2][3] = mlx_xpm_file_to_image(gm->mlx, "textures/em3.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[3][0] = mlx_xpm_file_to_image(gm->mlx, "textures/enemyr.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[3][1] = mlx_xpm_file_to_image(gm->mlx, "textures/em4.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[3][2] = mlx_xpm_file_to_image(gm->mlx, "textures/em5.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[3][3] = mlx_xpm_file_to_image(gm->mlx, "textures/em6.xpm",
			&gm->a.width, &gm->a.height);
}

static void	init_player(t_game *gm)
{
	gm->a.p[0][0] = mlx_xpm_file_to_image(gm->mlx, "textures/player.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.p[0][1] = mlx_xpm_file_to_image(gm->mlx, "textures/player1.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.p[0][2] = mlx_xpm_file_to_image(gm->mlx, "textures/player2.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.p[0][3] = mlx_xpm_file_to_image(gm->mlx, "textures/player3.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.p[1][0] = mlx_xpm_file_to_image(gm->mlx, "textures/player_r.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.p[1][1] = mlx_xpm_file_to_image(gm->mlx, "textures/player_r1.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.p[1][2] = mlx_xpm_file_to_image(gm->mlx, "textures/player_r2.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.p[1][3] = mlx_xpm_file_to_image(gm->mlx, "textures/player_r3.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[0][0] = mlx_xpm_file_to_image(gm->mlx, "textures/enemy.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[0][1] = mlx_xpm_file_to_image(gm->mlx, "textures/enemy1.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[0][2] = mlx_xpm_file_to_image(gm->mlx, "textures/enemy2.xpm",
			&gm->a.width, &gm->a.height);
	gm->a.n[0][3] = mlx_xpm_file_to_image(gm->mlx, "textures/enemy3.xpm",
			&gm->a.width, &gm->a.height);
	init_enemy(gm);
}

void	init_game(t_game *gm)
{
	(1) && (gm->side = 0, gm->nside = 0, gm->frame = 0, gm->nframe = 0);
	gm->win = mlx_new_window(gm->mlx,
			gm->a.width * 48, gm->a.height * 48, "game");
	if (!gm->win)
		on_destroy(gm, "Error: mlx_new_window failed\n", 0);
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
	init_player(gm);
	if (!gm->a.w || !gm->a.eo || !gm->a.ec || !gm->a.c || !gm->a.f
		|| !gm->a.p[0][0] || !gm->a.p[0][1] || !gm->a.p[0][2] || !gm->a.p[0][3]
		|| !gm->a.p[1][0] || !gm->a.p[1][1] || !gm->a.p[1][2] || !gm->a.p[1][3]
		|| !gm->a.n[0][0] || !gm->a.n[0][1] || !gm->a.n[0][2] || !gm->a.n[0][3]
		|| !gm->a.n[1][0] || !gm->a.n[1][1] || !gm->a.n[1][2] || !gm->a.n[1][3]
		|| !gm->a.n[2][0] || !gm->a.n[2][1] || !gm->a.n[2][2] || !gm->a.n[2][3]
		|| !gm->a.n[3][0] || !gm->a.n[3][1] || !gm->a.n[3][2] || !gm->a.n[3][3])
		on_destroy(gm, "Error: mlx_xpm_file_to_image failed\n", 1);
	ft_moves(gm, 0);
}

void	ft_put_image(t_game *gm, int x, int y)
{
	(1) && (x = 0, y = 0, mlx_clear_window(gm->mlx, gm->win));
	while (gm->mapf[x] != NULL)
	{
		if (gm->mapf[x][y] == '1' || gm->mapf[x][y] == ' ')
			mlx_put_image_to_window(gm->mlx, gm->win, gm->a.w, y * 48, x * 48);
		else if (gm->mapf[x][y] == '0')
			mlx_put_image_to_window(gm->mlx, gm->win, gm->a.f, y * 48, x * 48);
		else if (gm->mapf[x][y] == 'E' && gm->c != 0)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->a.ec, y * 48, x * 48);
		else if (gm->mapf[x][y] == 'E' && gm->c == 0)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->a.eo, y * 48, x * 48);
		else if (gm->mapf[x][y] == 'C')
			mlx_put_image_to_window(gm->mlx, gm->win, gm->a.c, y * 48, x * 48);
		else if (gm->mapf[x][y] == 'N')
			mlx_put_image_to_window(gm->mlx, gm->win,
				gm->a.n[gm->nside][gm->nframe], y * 48, x * 48);
		else if (gm->mapf[x][y] == 'P')
			mlx_put_image_to_window(gm->mlx, gm->win,
				gm->a.p[gm->side][gm->frame], y * 48, x * 48);
		if (gm->mapf[x][y + 1] == '\0')
			(1) && (x++, y = 0);
		else
			y++;
	}
	mlx_string_put(gm->mlx, gm->win, 10, 10, 0x00FFFFFF, gm->move);
}
