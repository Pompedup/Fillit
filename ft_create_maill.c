/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_maill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:30:30 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/29 11:53:46 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_reposition(t_tetri **pos)
{
	int i;
	int tx;
	int ty;

	tx = 0;
	while (tx == 0 || ty == 0)
	{
		tx = 0;
		ty = 0;
		i = 0;
		while (i < 4)
		{
			if (((*pos)->x[i]) % 5 == 0)
				tx++;
			if (((*pos)->y[i] % 5) == 0)
				ty++;
			i++;
		}
		if (!tx || !ty)
			ft_move(pos, tx, ty);
	}
}

int		ft_create_zelda(char *buffer, t_list **back, int *i)
{
	t_list		*tmp;
	t_tetri		*pos;

	if (!(pos = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	pos->c = *i + 65;
	ft_add_pos(pos, buffer);
	ft_reposition(&pos);
	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (0);
	tmp->content = pos;
	tmp->next = NULL;
	ft_lst_push_back(back, tmp);
	(*i)++;
	return (*i);
}

int		ft_check_around(char *buffer, int i)
{
	int nb_link;

	nb_link = 0;
	if (i > 5 && buffer[i - 5] == '#')
		++nb_link;
	if (i < 15 && buffer[i + 5] == '#')
		++nb_link;
	if (i > 1 && buffer[i - 1] == '#')
		++nb_link;
	if (i < 19 && buffer[i + 1] == '#')
		++nb_link;
	return (nb_link);
}

int		ft_check_form(char *buffer)
{
	int		i;
	int		nb_ht;
	int		nb_link;

	i = 0;
	nb_ht = 0;
	nb_link = 0;
	while (buffer[i])
	{
		if (((i + 1) % 5) == 0 && buffer[i] != '\n')
			return (0);
		else if (((i + 1) % 5) != 0 && buffer[i] != '.' && buffer[i] != '#')
			return (0);
		if (buffer[i] == '#')
		{
			nb_ht++;
			if (!(nb_link += ft_check_around(buffer, i)))
				return (0);
		}
		++i;
	}
	return ((nb_ht == 4 && i == 20 && nb_link >= 5) ? 1 : 0);
}

int		ft_check_file(char *name, t_list **back)
{
	int		file;
	char	buffer[21];
	int		i;
	int		end_buff;

	i = 0;
	*back = NULL;
	if ((file = open(name, O_RDONLY)) == -1)
		return (0);
	while ((end_buff = read(file, buffer, 20)))
	{
		buffer[end_buff] = 0;
		if (!ft_check_form(buffer))
			return (0);
		if (!ft_create_zelda(buffer, back, &i) || i > 26)
			return (0);
		if (!(read(file, buffer, 1)))
		{
			close(file);
			return (i);
		}
		if (*buffer != '\n')
			return (0);
	}
	return (0);
}
