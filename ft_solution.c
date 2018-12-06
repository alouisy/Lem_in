/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:21:51 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/20 13:21:54 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		no_bootloop(t_link *begin_list, t_room *room)
{
	t_link	*tmp;

	tmp = begin_list;
	while (tmp != NULL)
	{
		if (tmp->room == room)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_link	*which_one(t_link *begin_list, t_room *old_room, t_prms *prm)
{
	t_link	*n_link;
	t_link	*tmp;

	tmp = old_room->link;
	while (tmp != NULL)
	{
		if (no_bootloop(begin_list, tmp->room) && tmp->room->node != -1
			&& (tmp->room->stack == 0 || tmp->room == prm->end_room))
		{
			old_room->stack--;
			tmp->room->stack++;
			n_link = new_link(tmp->room);
			return (n_link);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_resolve2(t_link **path, t_link **copy, t_prms *prm)
{
	int		i;

	while (prm->end_room->stack != prm->nb_ant)
	{
		i = -1;
		while (++i < prm->nb_ant)
		{
			if (path[i] != NULL && path[i]->room != prm->end_room)
			{
				path[i]->next = which_one(copy[i], path[i]->room, prm);
				if (path[i]->next != NULL)
				{
					write(1, "L", 1);
					ft_putnbr(i + 1);
					write(1, "-", 1);
					ft_putstr(path[i]->next->room->name);
					write(1, " ", 1);
					path[i] = path[i]->next;
				}
			}
		}
		write(1, "\n", 1);
	}
}

void	ft_resolve(t_prms *prm)
{
	int		i;
	t_link	**path;
	t_link	**copy;

	write(1, "\n\nSOLUTION\n", 11);
	i = -1;
	path = (t_link **)malloc(sizeof(t_link *) * prm->nb_ant);
	copy = (t_link **)malloc(sizeof(t_link *) * prm->nb_ant);
	while (++i < prm->nb_ant)
	{
		path[i] = new_link(prm->start_room);
		copy[i] = path[i];
	}
	prm->start_room->stack = prm->nb_ant;
	ft_resolve2(path, copy, prm);
}
