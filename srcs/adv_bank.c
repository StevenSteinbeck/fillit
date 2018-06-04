/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilnite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:10:44 by kvilnite          #+#    #+#             */
/*   Updated: 2018/04/10 10:19:12 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**twod_store(char *str)
{	
	char **piece = NULL;
	int row = 0;
	int i = 0;

	piece = (char **)malloc(sizeof(char *) * 5);
	if (str[i] == 'o')
	{
		piece[row] = ft_strsub("##", 0, 2);
		piece[row + 1] = ft_strsub("##", 0, 2);
		return (piece);
	}
	if (str[i] == 'i' && str[i + 1] == '1')
	{
		piece[row] = ft_strsub("####", 0, 4);
		return (piece);
	}
	if (str[i] == 'i' && str[i + 1] == '2')
	{
		piece[row] = ft_strsub("#", 0, 1);
		piece[row + 1] = ft_strsub("#", 0, 1);
		piece[row + 2] = ft_strsub("#", 0, 1);
		piece[row + 3] = ft_strsub("#", 0, 1);
		return (piece);
	}
	if (str[i] == 's' && str[i + 1] == '1')
	{
		piece[row] = ft_strsub(".##", 0, 3);
		piece[row + 1] = ft_strsub("##", 0, 2);
		return (piece);
	}
	if (str[i] == 's' && str[i + 1] == '2')
	{
		piece[row] = ft_strsub("#", 0, 1);
		piece[row + 1] = ft_strsub("##", 0, 2);
		piece[row + 2] = ft_strsub(".#", 0, 2);
		return (piece);
	}
	if (str[i] == 'z' && str[i + 1] == '1')
	{
		piece[row] = ft_strsub("##", 0, 2);
		piece[row] = ft_strsub(".##", 0, 3);
		return (piece);
	}
	if (str[i] == 'z' && str[i + 1] == '2')
	{
		piece[row] = ft_strsub(".#", 0, 2);
		piece[row] = ft_strsub("##", 0, 2);
		piece[row] = ft_strsub("#", 0, 1);
		return (piece);
	}
	if (str[i] == 'l' && str[i + 1] == '1')
	{	
		piece[row] = ft_strsub("###", 0, 3);
		piece[row] = ft_strsub("#", 0, 1);
		return (piece);
	}
    if (str[i] == 'l' && str[i + 1] == '2')
	{
		piece[row] = ft_strsub("#", 0, 1);
		piece[row] = ft_strsub("#", 0, 1);
		piece[row] = ft_strsub("##", 0, 2);
	 	return (piece);
	}
    if (str[i] == 'l' && str[i + 1] == '3')
	{
		piece[row] = ft_strsub("..#", 0, 3);
		piece[row] = ft_strsub("###", 0, 3);
		return (piece);
	}
    if (str[i] == 'l' && str[i + 1] == '4')
	{
		piece[row] = ft_strsub("##", 0, 2);
		piece[row] = ft_strsub(".#", 0, 2);
		piece[row] = ft_strsub(".#", 0, 2);
		return (piece);
	}
	if (str[i] == 'j' && str[i + 1] == '1')
	{
		piece[row] = ft_strsub("###", 0, 3);
		piece[row] = ft_strsub("..#", 0, 3);
		return (piece);
	}
	if (str[i] == 'j' && str[i + 1] == '2')
	{
		piece[row] = ft_strsub("##", 0, 2);
		piece[row] = ft_strsub("#", 0, 1);
		piece[row] = ft_strsub("#", 0, 1);
		return (piece);
	}
	if (str[i] == 'j' && str[i + 1] == '3')
    {
		piece[row] = ft_strsub("#", 0, 1);
		piece[row] = ft_strsub("###", 0, 3);
	 	return (piece);
	}
	if (str[i] == 'j' && str[i + 1] == '4')
	{
		piece[row] = ft_strsub(".#", 0, 2);
		piece[row] = ft_strsub(".#", 0, 2);
		piece[row] = ft_strsub("##", 0, 2);
		return (piece);
	}
	if (str[i] == 't' && str[i + 1] == '1')
	{
		piece[row] = ft_strsub("###", 0, 3);
		piece[row] = ft_strsub(".#.", 0, 3);
		return (piece);
	}
    if (str[i] == 't' && str[i + 1] == '2')
	{
		piece[row] = ft_strsub("#", 0, 1);
		piece[row] = ft_strsub("##", 0, 2);
		piece[row] = ft_strsub("#", 0, 1);
		return (piece);
	}
    if (str[i] == 't' && str[i + 1] == '3')
	{
		piece[row] = ft_strsub(".#.", 0, 3);
		piece[row] = ft_strsub("###", 0, 3);
		return (piece);
	}
    if (str[i] == 't' && str[i + 1] == '4')
	{
		piece[row] = ft_strsub(".#", 0, 2);
		piece[row] = ft_strsub("##", 0, 2);
		piece[row] = ft_strsub(".#", 0, 2);
		return (piece);
	}
	return (0);
}

char **twod_convert(char **str, int a)
{
	int i = 0;
	int tetri = 0;

	while (str[tetri] != 0)
	{
		i = 0;
		while (str[tetri][i] != '\0')
		{
			if (str[tetri][i] == '#')
				str[tetri][i] = (char)a;
			i++;
		}
		tetri++;
	}
	return (str);
} 
