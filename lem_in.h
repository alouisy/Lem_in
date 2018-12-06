/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:15:47 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/20 14:15:53 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

# define WIN_LENGTH 1000
# define WIN_HEIGHT 1000
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_PLUS 69
# define KEY_LESS 78
# define KEY_S 1
# define KEY_W 13

typedef struct		s_prms
{
	int				nb_ant;
	int				nb_room;
	int				check_start;
	int				check_end;
	char			*text;
	char			**tab;
	struct s_room	*start_room;
	struct s_room	*end_room;
	struct s_room	*list_room;
	struct s_gfx	*gfx;
	int				b_gfx;
	int				b_link;
	int				b_node;
	int				b_param;
}					t_prms;

typedef struct		s_room
{
	char			*name;
	int				type;
	int				coord_x;
	int				coord_y;
	int				fx_x;
	int				fx_y;
	int				node;
	int				stack;
	int				nb_link;
	struct s_link	*link;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	struct s_room	*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_gfx
{
	int				move_x;
	int				move_y;
	int				zoom;
	int				down;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bbp;
	int				size_line;
	int				endian;
}					t_gfx;

typedef struct		s_trace
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_trace;

t_room				*new_room(char **tab, int type);
void				add_room(char **tab, int type, t_prms *prm);
t_link				*new_link(t_room *room);
void				add_link(t_room *room1, t_room *room2);
void				make_link(char **tab, t_prms *prm);
int					split_n_get(char *line, int type, int check, t_prms *prm);
int					ft_analyse(int *i, int check, t_prms *prm);
void				get_info(t_prms *prm);
void				prm_init(t_prms *prm);
int					no_bootloop(t_link *begin_list, t_room *room);
t_link				*which_one(t_link *begin_list,
	t_room *old_room, t_prms *prm);
void				ft_resolve(t_prms *prm);
void				node(t_room *room, int len, t_prms *prm);
int					swapy_node(t_link *begin_list);
void				sort_link(t_prms *prm);
void				print_prms(t_prms *prm);
void				print_nodes(t_room *list_room);
void				print_links(t_room *list_room);
int					stupid_or_not(t_prms *prm);
int					ft_bonus(char *command, t_prms *prm);
void				print_bonus(int	i, t_prms *prm);

int					key_style(int keycode, t_prms *prm);
void				ft_fx(t_gfx *gfx, t_prms *prm);
void				ft_trace(t_trace *coor, t_gfx *gfx);
void				ft_filltrace(t_trace *coor, t_room *room1,
	t_room *room2, t_gfx *gfx);
void				lem_in_graphic(t_gfx *gfx, t_prms *prm);
t_gfx				*gfx_init(void);
void				gfx(t_prms *prm);

#endif
