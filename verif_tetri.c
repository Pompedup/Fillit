/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:18:01 by abezanni          #+#    #+#             */
/*   Updated: 2018/12/18 20:25:39 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	verif_link(char *buff, int i)
{
	int nb_link;

	nb_link = 0;
	if (i > 4 && buff[i - 5] == '#')
		nb_link++;
	if (i < 15 && buff[i + 5] == '#')
		nb_link++;
	if (i > 0 && buff[i - 1] == '#')
		nb_link++;
	if (i < 19 && buff[i + 1] == '#')
		nb_link++;
	return (nb_link);
}

int	verif_tetri(char *buff)
{
	int	i;
	int nb_hashtag;
	int nb_link;

	i = 0;
	nb_hashtag = 0;
	nb_link = 0;
	while (i < 20)
	{
		if ((i + 1) % 5 == 0 && buff[i] != '\n')
			return (0);
		else if ((i + 1) % 5 != 0 && buff[i] != '#' && buff[i] != '.')
			return (0);
		if (buff[i] == '#')
		{
			nb_hashtag++;
			if (!(nb_link += verif_link(buff, i)))
				return (0);
		}
		i++;
	}
	return (0);
}
