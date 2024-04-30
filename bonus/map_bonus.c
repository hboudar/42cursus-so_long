/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:23:24 by hboudar           #+#    #+#             */
/*   Updated: 2024/03/30 06:57:19 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	line_shap(t_game *gm, char *line, char *wall)
{
	static int	l_size = 0;
	int			i;

	if (!line || !wall)
		on_destroy(gm, "Error: malloc failed\n", 0);
	else if (!l_size && wall[0])
		on_destroy(gm, "Error: map not surrounded by walls\n", 0);
	else if (line[0])
		on_destroy(gm, "Error: invalid character(s) in map\n", 0);
	i = -1;
	while (gm->l[++i] && gm->l[i] != '\n')
	{
		gm->p += (gm->l[i] == 'P');
		gm->e += (gm->l[i] == 'E');
		gm->c += (gm->l[i] == 'C');
		gm->n += (gm->l[i] == 'N');
	}
	if (l_size == 0)
		l_size = i;
	else if (l_size != i)
		on_destroy(gm, "Error: map not rectangular\n", 0);
	else if (gm->l[0] != '1' || gm->l[i - 1] != '1')
		on_destroy(gm, "Error: map not surrounded by walls\n", 0);
	(1) && (free(line), free(wall), i = 0);
}

int	check_map(char *file, t_game *gm, char *l, char	*w)
{
	(1) && (gm->p = 0, gm->c = 0, gm->e = 0, gm->n = 0);
	if (!l || l[1] != 'b' || l[2] != 'e' || l[3] != 'r' || l[4] != '\0')
		on_destroy(gm, "Error: invalid map file\n", 0);
	gm->fd = open(file, O_RDONLY);
	if (gm->fd == -1)
		on_destroy(gm, "Error: open failed\n", 0);
	gm->l = get_next_line(gm->fd);
	if (!gm->l)
		on_destroy(gm, "Error: empty map\n", 0);
	while (gm->l != NULL)
	{
		if (w)
			free (w);
		w = ft_strdup(gm->l);
		(!w) && (free(gm->l), on_destroy(gm, "Error: malloc failed\n", 0));
		line_shap(gm, ft_strtrim(gm->l, "01CEPN\n"), ft_strtrim(gm->l, "1\n"));
		free (gm->l);
		gm->l = get_next_line(gm->fd);
	}
	l = ft_strtrim(w, "1\n");
	(!l || l[0]) && (on_destroy(gm, "Error: map not surrounded by walls\n", 0));
	if (gm->p != 1 || gm->e != 1 || gm->c < 1 || gm->n != 1)
		on_destroy(gm, "Error: invalid number of character(s)\n", 0);
	(1) && (free(l), free(w), close(gm->fd), gm->m = 0);
	return (0);
}
