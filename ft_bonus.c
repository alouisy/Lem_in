/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:12:32 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/20 14:12:33 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_bonus(int i, t_prms *prm)
{
	if (i == 0)
	{
		if (prm->b_param == 1)
			print_prms(prm);
		if (prm->b_link == 1)
			print_links(prm->list_room);
		if (prm->b_node == 1)
			print_nodes(prm->list_room);
	}
	else
	{
		if (prm->b_gfx == 1)
			gfx(prm);
	}
}

void	print_prms(t_prms *prm)
{
	write(1, "\n\nBONUS - PRINT PARAMS\n", 23);
	write(1, "> Number of ant : ", 18);
	ft_putnbr(prm->nb_ant);
	write(1, "\n> Number of room : ", 20);
	ft_putnbr(prm->nb_room);
	write(1, "\n> Name of the start room : \"", 29);
	ft_putstr(prm->start_room->name);
	write(1, "\"\n> Name of the end room : \"", 28);
	ft_putstr(prm->end_room->name);
	write(1, "\"", 1);
}

void	print_nodes(t_room *list_room)
{
	t_room	*list;

	list = list_room;
	write(1, "\n\nBONUS - PRINT NODES", 21);
	while (list != NULL)
	{
		write(1, "\n> Room \"", 9);
		ft_putstr(list->name);
		write(1, "\" | node = ", 11);
		ft_putnbr(list->node);
		list = list->next;
	}
}

void	print_links(t_room *list_room)
{
	t_room	*list;
	t_link	*link;

	list = list_room;
	write(1, "\n\nBONUS - PRINT LINKS", 21);
	while (list != NULL)
	{
		write(1, "\n> Room \"", 9);
		ft_putstr(list->name);
		write(1, "\"\n  (", 5);
		ft_putnbr(list->nb_link);
		write(1, " links)", 7);
		link = list->link;
		while (link != NULL)
		{
			write(1, " -> ", 4);
			ft_putstr(link->room->name);
			link = link->next;
		}
		list = list->next;
	}
}
