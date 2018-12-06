/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:21:25 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/20 13:21:28 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(char **tab, int type)
{
	t_room	*room;

	room = (t_room *)malloc(sizeof(t_room));
	if (room)
	{
		room->name = ft_strdup(tab[0]);
		room->type = type;
		room->coord_x = ft_atoi(tab[1]);
		room->coord_y = ft_atoi(tab[2]);
		room->fx_x = 0;
		room->fx_y = 0;
		room->node = -1;
		room->stack = 0;
		room->nb_link = 0;
		room->link = NULL;
		room->next = NULL;
	}
	return (room);
}

void	add_room(char **tab, int type, t_prms *prm)
{
	t_room	*list;

	if (prm->list_room == NULL)
	{
		prm->list_room = new_room(tab, type);
		list = prm->list_room;
	}
	else
	{
		list = prm->list_room;
		while (list->next != NULL)
			list = list->next;
		list->next = new_room(tab, type);
		list = list->next;
	}
	if (type == 0)
	{
		list->node = -2;
		prm->start_room = list;
	}
	if (type == 2)
		prm->end_room = list;
}

t_link	*new_link(t_room *room)
{
	t_link	*link;

	link = (t_link *)malloc(sizeof(t_link));
	if (link)
	{
		link->room = room;
		link->next = NULL;
	}
	return (link);
}

void	add_link(t_room *room1, t_room *room2)
{
	t_link	*link;
	int		check;

	check = 0;
	if (room1->link == NULL)
		room1->link = new_link(room2);
	else
	{
		link = room1->link;
		while (link->next != NULL)
		{
			if (link->room == room2)
				check++;
			link = link->next;
		}
		if (check == 0)
			link->next = new_link(room2);
	}
	room1->nb_link++;
}

void	make_link(char **tab, t_prms *prm)
{
	t_room	*list;
	t_room	*room1;
	t_room	*room2;

	list = prm->list_room;
	room1 = list;
	room2 = list;
	while (list != NULL && (ft_strcmp(room1->name, tab[0]) != 0
		|| ft_strcmp(room2->name, tab[1]) != 0))
	{
		if (ft_strcmp(list->name, tab[0]) == 0)
			room1 = list;
		if (ft_strcmp(list->name, tab[1]) == 0)
			room2 = list;
		list = list->next;
	}
	add_link(room1, room2);
	add_link(room2, room1);
}
