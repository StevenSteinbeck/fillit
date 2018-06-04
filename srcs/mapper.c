/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elliotmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:21:20 by stestein          #+#    #+#             */
/*   Updated: 2018/03/23 09:22:24 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**mapgen(int size)
{
	char 	**map;
	int		i;
	int 	j;

	j = size;
	i = 0;
	map = ft_memalloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		map[i] = ft_strnew(size);
		map[i] = ft_memset(map[i], 46, size);
		i++;
	}
	map[i] = NULL;
	return (map);
}
