/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:10:15 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/01 14:11:38 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_game *gm, char *msg, int mode)
{
	if (mode)
	{
		(gm->a.p[0]) && (mlx_destroy_image(gm->mlx, gm->a.p[0]));
		(gm->a.p[1]) && (mlx_destroy_image(gm->mlx, gm->a.p[1]));
		(gm->a.w) && (mlx_destroy_image(gm->mlx, gm->a.w));
		(gm->a.eo) && (mlx_destroy_image(gm->mlx, gm->a.eo));
		(gm->a.ec) && (mlx_destroy_image(gm->mlx, gm->a.ec));
		(gm->a.c) && (mlx_destroy_image(gm->mlx, gm->a.c));
		(gm->a.f) && (mlx_destroy_image(gm->mlx, gm->a.f));
		mlx_destroy_window(gm->mlx, gm->win);
		if (mode == 1)
			ft_printf("%s\n", msg);
		else
			ft_printf("Window closed 'X'\n");
		exit(0);
	}
	else
	{
		write(2, msg, ft_strlen(msg));
		exit(1);
	}
	return (0);
}
