/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:20:52 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/01 14:11:40 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int key, t_game *gm)
{
	int	m;
	int	x;
	int	y;

	m = -1;
	find_player(gm, &x, &y);
	(key == 53) && (on_destroy(gm, "Game closed", 1));
	(key == 124) && (m = move_right(gm, x, y));
	(key == 123) && (m = move_left(gm, x, y));
	(key == 126) && (m = move_up(gm, x, y));
	(key == 125) && (m = move_down(gm, x, y));
	if (m == 0)
	{
		ft_printf("Move: %d\n", gm->m);
		gm->m++;
		ft_put_image(gm);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_game	gm;

	if (ac != 2 || check_map(av[1], &gm, ft_strrchr(av[1], '.'), NULL))
		on_destroy(&gm, "Error: Wrong number of arguments\n", 0);
	is_reachable(&gm, av[1]);
	gm.mlx = mlx_init();
	if (gm.mlx == NULL)
		on_destroy(&gm, "Error: mlx_init failed\n", 0);
	init_game(&gm);
	mlx_key_hook(gm.win, &on_keypress, &gm);
	mlx_hook(gm.win, 17, 0, &on_destroy, &gm);
	mlx_loop(gm.mlx);
	exit (0);
}
