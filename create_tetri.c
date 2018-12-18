/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:27:02 by abezanni          #+#    #+#             */
/*   Updated: 2018/12/18 20:33:26 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	create_tetri(char *buff, t_tetri **lst, int nb_pieces)
{
	while (*lst)
		lst = &(*lst)->next;
	if (!(*lst = malloc(sizeof(t_tetri))))
		return (0);
	(*lst)->next = NULL;

	return (1);
}
