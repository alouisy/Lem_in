/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:21:35 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/20 13:21:36 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_bonus(char *command, t_prms *prm)
{
	if (ft_strcmp(command, "#gfx") == 0)
		prm->b_gfx = 1;
	if (ft_strcmp(command, "#node") == 0)
		prm->b_node = 1;
	if (ft_strcmp(command, "#link") == 0)
		prm->b_link = 1;
	if (ft_strcmp(command, "#param") == 0)
		prm->b_param = 1;
	return (1);
}

int		split_n_get(char *line, int type, int check, t_prms *prm)
{
	char	**split;

	if (ft_how_many_c(line, ' ') == 2 && ft_how_many_c(line, '-') == 0)
	{
		if (check > 1)
			return (0);
		prm->nb_room++;
		split = ft_strsplit(line, ' ');
		add_room(split, type, prm);
		return (1);
	}
	if (ft_how_many_c(line, '-') == 1 && ft_how_many_c(line, ' ') == 0)
	{
		if (check != 1 && check != 2)
			return (0);
		split = ft_strsplit(line, '-');
		make_link(split, prm);
		return (2);
	}
	return (0);
}

int		ft_analyse(int *i, int check, t_prms *prm)
{
	int		ret;

	ret = 0;
	if ((prm->tab[*i][0] != '#' && ft_strlen(prm->tab[*i]) < 3)
		|| (ft_strcmp(prm->tab[*i], "##start") == 0 && prm->check_start == 1)
		|| (ft_strcmp(prm->tab[*i], "##end") == 0 && prm->check_end == 1))
		return (0);
	else if (ft_strcmp(prm->tab[*i], "##start") == 0 && prm->check_start == 0)
	{
		prm->check_start += 1;
		(*i)++;
		ret = split_n_get(prm->tab[*i], 0, check, prm);
	}
	else if (ft_strcmp(prm->tab[*i], "##end") == 0 && prm->check_end == 0)
	{
		prm->check_end += 1;
		(*i)++;
		ret = split_n_get(prm->tab[*i], 2, check, prm);
	}
	else if (prm->tab[*i][0] == '#')
		return (ft_bonus(prm->tab[*i], prm));
	else
		ret = split_n_get(prm->tab[*i], 1, check, prm);
	return (ret);
}

void	get_info(t_prms *prm)
{
	int		i;
	int		check;

	i = 0;
	check = -1;
	prm->nb_ant = ft_atoi(prm->tab[0]);
	if (prm->nb_ant > 0 && prm->tab != NULL)
	{
		while (prm->tab[++i] != NULL && check != 0)
			check = ft_analyse(&i, check, prm);
	}
	else
		ft_error("ERROR", 1);
}
