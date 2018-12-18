/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:58:04 by glebouch          #+#    #+#             */
/*   Updated: 2018/12/18 20:30:47 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef	struct	s_tetri{
	int				x[4];
	int				y[4];
	char			c;
	struct s_tetri	*next;
}				t_tetri;

void			ft_reposition(t_tetri **pos);
int				ft_create_zelda(char *str, t_list **back, int *i);
int				ft_check_around(char *str, int i);
int				ft_check_form(char *buffy);
int				ft_check_file(char *name, t_list **back);
int				ft_racine_sup(int nb_pieces);
int				ft_back_track(t_list **list, char *tab,
				int *nb_essai, int size);
void			ft_write_char(char *tab, t_tetri *pos, int size, int nb_essai);
int				ft_ispoint(t_tetri *pos, char *tab, int size, int *nb_essai);
int				ft_resolve(int nb_pieces, t_list *ma_list);
void			ft_erase_list(t_list *ma_list);
char			*ft_init_tab(char *tab, int size);
void			ft_move(t_tetri **pos, int tx, int ty);
void			ft_add_pos(t_tetri *pos, char *buffer);

#endif
