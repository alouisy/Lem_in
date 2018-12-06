/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 21:51:56 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/12 21:57:30 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	prm_init(t_prms *prm)
{
	prm->nb_ant = 0;
	prm->nb_room = 0;
	prm->check_start = 0;
	prm->check_end = 0;
	prm->text = NULL;
	prm->tab = NULL;
	prm->start_room = NULL;
	prm->end_room = NULL;
	prm->list_room = NULL;
	prm->b_link = 0;
	prm->b_param = 0;
	prm->b_gfx = 0;
	prm->b_node = 0;
}

int		main(int argc, char *argv[])
{
	t_prms	prm;
	int		fd;

	prm_init(&prm);
	if (argc == 1 || argc == 2)
	{
		fd = (argc == 1) ? 0 : safe_open(argv[1]);
		prm.text = ft_get_file(fd);
		ft_putstr(prm.text);
		prm.tab = ft_strsplit(prm.text, '\n');
		get_info(&prm);
		node(prm.end_room, 0, &prm);
		if (!stupid_or_not(&prm))
			ft_error("\n\nERROR", 1);
		sort_link(&prm);
		print_bonus(0, &prm);
		ft_resolve(&prm);
		print_bonus(1, &prm);
	}
	else
		ft_error("BAD INPUT !", 1);
	return (0);
}
