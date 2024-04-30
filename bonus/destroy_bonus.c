/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:19:36 by hboudar           #+#    #+#             */
/*   Updated: 2024/04/01 14:12:48 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	on_destroy_xpm(t_game *gm, int i, int j)
{
	while (i < 2)
	{
		if (j != 4)
		{
			(gm->a.p[i][j]) && (mlx_destroy_image(gm->mlx, gm->a.p[i][j]));
			(gm->a.n[i][j]) && (mlx_destroy_image(gm->mlx, gm->a.n[i][j]));
			(gm->a.n[i + 2][j])
				&& (mlx_destroy_image(gm->mlx, gm->a.n[i + 2][j]));
			j++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	(gm->a.w) && (mlx_destroy_image(gm->mlx, gm->a.w));
	(gm->a.eo) && (mlx_destroy_image(gm->mlx, gm->a.eo));
	(gm->a.ec) && (mlx_destroy_image(gm->mlx, gm->a.ec));
	(gm->a.c) && (mlx_destroy_image(gm->mlx, gm->a.c));
	(gm->a.f) && (mlx_destroy_image(gm->mlx, gm->a.f));
}

int	on_destroy(t_game *gm, char *str, int mode)
{
	if (mode)
	{
		on_destroy_xpm(gm, 0, 0);
		mlx_destroy_window(gm->mlx, gm->win);
		if (mode == 1)
			ft_printf("%s", str);
		else
			ft_printf("Window closed 'X'\n");
		exit(0);
	}
	else
	{
		write(2, str, ft_strlen(str));
		exit(1);
	}
	return (0);
}
