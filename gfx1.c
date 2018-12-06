/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:22:02 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/20 13:22:04 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_graphic(t_gfx *gfx, t_prms *prm)
{
	t_link		*link;
	t_room		*list_room;
	t_trace		*coor;

	list_room = prm->list_room;
	coor = (t_trace *)malloc(sizeof(t_trace));
	while (list_room != NULL)
	{
		link = list_room->link;
		mlx_string_put(gfx->mlx, gfx->win, (list_room->fx_x / gfx->down)
			+ gfx->move_x - 15, (-list_room->fx_y / gfx->down)
			+ gfx->move_y - 15, 0x0033FF, list_room->name);
		while (link != NULL)
		{
			ft_filltrace(coor, list_room, link->room, gfx);
			link = link->next;
		}
		list_room = list_room->next;
	}
}

void	ft_fx(t_gfx *gfx, t_prms *prm)
{
	t_room	*tmp;

	tmp = prm->list_room;
	while (tmp != NULL)
	{
		tmp->fx_x = tmp->coord_x * gfx->zoom;
		tmp->fx_y = tmp->coord_y * gfx->zoom;
		tmp = tmp->next;
	}
}

t_gfx	*gfx_init(void)
{
	t_gfx	*gfx;

	gfx = (t_gfx *)malloc(sizeof(t_gfx));
	gfx->move_x = 500;
	gfx->move_y = 500;
	gfx->zoom = 5;
	gfx->down = 1;
	return (gfx);
}

void	gfx(t_prms *prm)
{
	prm->gfx = gfx_init();
	prm->gfx->mlx = mlx_init();
	prm->gfx->win = mlx_new_window(prm->gfx->mlx,
		WIN_LENGTH, WIN_HEIGHT, "Lem_in GFX");
	ft_fx(prm->gfx, prm);
	lem_in_graphic(prm->gfx, prm);
	mlx_key_hook(prm->gfx->win, key_style, prm);
	mlx_loop(prm->gfx->mlx);
}
