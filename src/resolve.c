/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:07:43 by abezanni          #+#    #+#             */
/*   Updated: 2018/12/18 19:28:07 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_ispoint(t_tetri *pos, char *tab, int size, int *nb_essai)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (pos->x[i] + pos->y[i] * size + *nb_essai < size * (size + 1))
		{
			if (tab[pos->x[i] + pos->y[i] * (size + 1) + *nb_essai] != '.')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

void	ft_write_char(char *tab, t_tetri *pos, int size, int nb_essai)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (tab[pos->x[i] + pos->y[i] * (size + 1) + nb_essai] == '.')
			tab[pos->x[i] + pos->y[i] * (size + 1) + nb_essai] = pos->c;
		else
			tab[pos->x[i] + pos->y[i] * (size + 1) + nb_essai] = '.';
	}
}

int		ft_back_track(t_list **list, char *tab, int *nb_essai, int size)
{
	int			next_pos;
	t_tetri		*pos;

	next_pos = 0;
	pos = (t_tetri*)((*list)->content);
	if (*nb_essai < size * (size + 1) && ft_ispoint(pos, tab, size, nb_essai))
	{
		ft_write_char(tab, pos, size, *nb_essai);
		if ((*list)->next)
		{
			while (next_pos <= size * (size + 1))
			{
				if (ft_back_track(&((*list)->next), tab, &next_pos, size))
					return (1);
				next_pos++;
			}
		}
		if (next_pos)
		{
			ft_write_char(tab, pos, size, *nb_essai);
			return (0);
		}
		return (1);
	}
	return (0);
}
