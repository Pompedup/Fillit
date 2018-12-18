/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:44:44 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/29 11:59:34 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_move(t_tetri **pos, int tx, int ty)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!tx)
			((*pos)->x[i])--;
		if (!ty)
			((*pos)->y[i])--;
		i++;
	}
}

void	ft_add_pos(t_tetri *pos, char *buffer)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (buffer[j])
	{
		if (buffer[j] == '#')
		{
			pos->x[k] = j % 5;
			pos->y[k] = j / 5;
			k++;
		}
		j++;
	}
}
