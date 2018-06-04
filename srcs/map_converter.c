/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:40:01 by stestein          #+#    #+#             */
/*   Updated: 2018/03/28 16:55:11 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		size(char **map)
{
	int i;
	int row;

	row = 0;
	i = 0;
	while (map[row][i])
		i++;
	return (i);
}

char	*map_converter(char **map)
{
	int row;
	int i;
	char *str;
	int j;
	int siz;

	siz = size(map);
	str = (char *)malloc(sizeof(*str) * (siz * siz) + siz);
	row = 0;
	i = 0;
	j = 0;
	while (map[row])
	{
		while (map[row][i])
		{
			while (!(map[row][i] == '\0'))
			{
				str[j] = map[row][i];
				i++;
				j++;
			}
			str[j] = '\n';
			j++;
			break ;
		}
		row++;
		i = 0;
	}
	return (str);
}

