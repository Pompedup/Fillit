/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:19:31 by abezanni          #+#    #+#             */
/*   Updated: 2017/11/28 16:28:30 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_racine_sup(int nb_pieces)
{
	int i;

	i = 2;
	while (i * i < nb_pieces * 4)
		i++;
	return (i);
}

char	*ft_init_tab(char *tab, int size)
{
	int i;
	int total;

	i = 0;
	total = size * (size + 1);
	if (!(tab = (char*)malloc(total)))
		return (0);
	tab[total] = 0;
	while (i < total)
	{
		if ((i % (size + 1)) == size)
			tab[i] = '\n';
		else
			tab[i] = '.';
		i++;
	}
	return (tab);
}

void	ft_erase_list(t_list *ma_list)
{
	if (ma_list)
	{
		if (ma_list->next)
			ft_erase_list(ma_list->next);
		free(ma_list->content);
		free(ma_list);
	}
}

int		ft_resolve(int nb_pieces, t_list *ma_list)
{
	char	*tab;
	int		size;
	int		nb_essai;

	size = ft_racine_sup(nb_pieces);
	tab = NULL;
	if (!(tab = ft_init_tab(tab, size)))
		return (0);
	nb_essai = 0;
	while (!(ft_back_track(&ma_list, tab, &nb_essai, size)))
	{
		if (nb_essai >= size * (size + 1))
		{
			size++;
			free(tab);
			if (!(tab = ft_init_tab(tab, size)))
				return (0);
			nb_essai = -1;
		}
		nb_essai++;
	}
	ft_putstr(tab);
	free(tab);
	ft_erase_list(ma_list);
	return (1);
}

int		main(int ac, char **av)
{
	t_list	*ma_list;
	int		nb_pieces;

	if (ac == 2)
	{
		if (((nb_pieces = ft_check_file((av[1]), &ma_list)) == 0))
			ft_putstr("error\n");
		else
		{
			if (!(ft_resolve(nb_pieces, ma_list)))
				ft_putstr("error\n");
		}
	}
	else
		ft_putstr("usage: fillit source_file\n");
	return (0);
}
