/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presolve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:21:42 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/20 13:21:43 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		stupid_or_not(t_prms *prm)
{
	t_link	*tmp;
	int		i;

	i = 0;
	if ((prm->start_room == prm->end_room) || (prm->start_room->link == NULL)
		|| (prm->end_room->link == NULL))
		return (0);
	tmp = prm->start_room->link;
	while (tmp != NULL)
	{
		if (tmp->room->node != -1)
			i++;
		tmp = tmp->next;
	}
	return ((i > 0) ? 1 : 0);
}

int		swapy_node(t_link *begin_list)
{
	t_link	*link;
	t_room	*tmp;
	int		i;

	i = 0;
	link = begin_list;
	while (link->next != NULL)
	{
		if (link->next->room->node < link->room->node)
		{
			tmp = link->room;
			link->room = link->next->room;
			link->next->room = tmp;
			i++;
		}
		link = link->next;
	}
	return (i);
}

void	sort_link(t_prms *prm)
{
	t_room	*tmp;

	tmp = prm->list_room;
	while (tmp != NULL)
	{
		while (tmp->link != NULL && swapy_node(tmp->link) != 0)
			;
		tmp = tmp->next;
	}
}

void	node(t_room *room, int len, t_prms *prm)
{
	t_link	*tmp;

	if (room != prm->start_room && (room->node == -1 || room->node > len))
	{
		room->node = len;
		tmp = room->link;
		while (tmp != NULL)
		{
			node(tmp->room, len + 1, prm);
			tmp = tmp->next;
		}
	}
}
