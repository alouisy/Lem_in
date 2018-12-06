/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:22:08 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/20 13:22:10 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		key_style(int keycode, t_prms *prm)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		prm->gfx->move_x += (keycode == KEY_LEFT) ? -30 : 30;
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
		prm->gfx->move_y += (keycode == KEY_UP) ? -30 : 30;
	else if (keycode == KEY_LESS && prm->gfx->zoom >= 6)
		prm->gfx->zoom -= 5;
	else if (keycode == KEY_PLUS && prm->gfx->zoom <= 65)
		prm->gfx->zoom += 5;
	else if (keycode == KEY_W && prm->gfx->down >= 6)
		prm->gfx->down -= 5;
	else if (keycode == KEY_S && prm->gfx->down <= 145)
		prm->gfx->down += 5;
	else
		return (0);
	ft_fx(prm->gfx, prm);
	mlx_clear_window(prm->gfx->mlx, prm->gfx->win);
	lem_in_graphic(prm->gfx, prm);
	return (0);
}

void	ft_trace(t_trace *coor, t_gfx *gfx)
{
	int		tab[4];
	int		err;
	int		e2;

	tab[0] = abs(coor->x2 - coor->x1);
	tab[1] = abs(coor->y2 - coor->y1);
	tab[2] = coor->x1 < coor->x2 ? 1 : -1;
	tab[3] = coor->y1 < coor->y2 ? 1 : -1;
	err = (tab[0] > tab[1] ? tab[0] : -tab[1]) / 2;
	while (1)
	{
		mlx_pixel_put(gfx->mlx, gfx->win, coor->x1 + gfx->move_x,
			coor->y1 + gfx->move_y, 0xCC0000);
		if (coor->x1 == coor->x2 && coor->y1 == coor->y2)
			break ;
		e2 = err;
		if (e2 > -tab[0])
			err -= tab[1];
		if (e2 > -tab[0])
			coor->x1 += tab[2];
		if (e2 < tab[1])
			err += tab[0];
		if (e2 < tab[1])
			coor->y1 += tab[3];
	}
}

void	ft_filltrace(t_trace *coor, t_room *room1, t_room *room2, t_gfx *gfx)
{
	coor->x1 = room1->fx_x / gfx->down;
	coor->y1 = -room1->fx_y / gfx->down;
	coor->x2 = room2->fx_x / gfx->down;
	coor->y2 = -room2->fx_y / gfx->down;
	ft_trace(coor, gfx);
}
