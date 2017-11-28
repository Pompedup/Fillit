/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_maill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:30:30 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/28 16:26:12 by abezanni         ###   ########.fr       */
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

int		ft_create_zelda(char *str, t_list **back, int *i)
{
	t_list		*tmp;
	t_tetri		*pos;
	int			j;
	int			k;

	if (!(pos = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	j = 0;
	k = 0;
	pos->c = *i + 65;
	while (str[j])
	{
		if (str[j] == '#')
		{
			pos->x[k] = j % 5;
			pos->y[k] = j / 5;
			k++;
		}
		j++;
	}
	ft_reposition(&pos);
	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (0);
	tmp->content = pos;
	tmp->next = NULL;
	ft_lst_push_back(back, tmp);
	(*i)++;
	return (*i);
}

int		ft_check_around(char *str, int i)
{
	int ibool;

	ibool = 0;
	if (i > 5 && str[i - 5] == '#')
		++ibool;
	if (i < 15 && str[i + 5] == '#')
		++ibool;
	if (i > 1 && str[i - 1] == '#')
		++ibool;
	if (i < 19 && str[i + 1] == '#')
		++ibool;
	return (ibool);
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
