/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:11:43 by abezanni          #+#    #+#             */
/*   Updated: 2018/12/18 20:31:05 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			read_file(char *file_name, t_tetri **lst)
{
	int		nb_pieces;
	char	buff[22];
	int		ret;
	int		fd;

	nb_pieces = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		if (!verif_tetri(buff))
			return (0);
		if (!create_link(buff, lst, &nb_pieces))
			return (0);
	}
	return (nb_pieces);
}
