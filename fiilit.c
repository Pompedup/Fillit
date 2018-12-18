/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fiilit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:08:43 by abezanni          #+#    #+#             */
/*   Updated: 2018/12/18 20:30:22 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av)
{
	t_tetri	*lst;
	int		nb_pieces;

	if (ac == 2)
	{
		lst = NULL;
		if ((nb_pieces = read_file(av[1], &lst)) == 0)
			ft_putendl("error");
		else if (resolve(nb_pieces, lst))
			ft_putendl("error");
	}
	else
		ft_putendl("usage: fillit source_file");
}
