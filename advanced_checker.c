/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:10:53 by stestein          #+#    #+#             */
/*   Updated: 2018/03/15 16:43:36 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*shape_detector(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			break ;
		i++;
	}
	//2nd block next to 1st
	if (str[i + 1] == '#')
	{
		//3rd block under 1st
		if (str[i + 5] == '#')
		{
			//4th block under 2nd
			if (str[i + 6] == '#')
				return ("o");
			//4th block under 3rd
			if (str[i + 10] == '#')
				return ("j2");
			//4th block next to 2nd
			if (str[i + 2] == '#')
				return ("l1");
		}
		//3rd block under 2nd
		if (str[i + 6] == '#')
		{
			//4th block next to 3rd
			if (str[i + 7] == '#')
				return ("z1");
			//4th block under 3rd
			if (str[i + 11] == '#')
				return ("l4");
			//4th block next to 2nd
			if (str[i + 2] == '#')
				return ("t1");
		}
		//3rd block next to 2nd
		if (str[i + 2] == '#')		
		{
			//4rth block next to 3rd
			if (str[i + 3] == '#')
				return ("i1");
			//4th block under 3rd
			if (str[i + 7] == '#')
				return ("j1");
		}
		//3rd block under and to left of 1st
		if (str[i + 4] == '#')
		{
			//4th block next to 3rd, under 1st
			if (str[i + 5] == '#')
				return ("s1");
		}
	}
	//2nd block under 1st
	if (str[i + 5] == '#')
	{
		//3rd block next to 2nd
		if (str[i + 6] == '#')
		{
			//4th block under 3rd
			if (str[i + 11] == '#')
				return ("s2");
			//4th block next to 3rd
			if (str[i + 7] == '#')
				return ("j3");
			//4th block left of 2nd
			if (str[i + 4] == '#')
				return ("t3");
			//4th block under 2nd
			if (str[i + 10] == '#')
				return ("t2");
		}
		//3rd block under 2nd
		if (str[i + 10] == '#')
		{
			//4th block under 3rd
			if (str[i + 15] == '#')
				return ("i2");
			//4th block right of 3rd
			if (str[i + 11] == '#')
				return ("l2");
			//4th block left of 3rd
			if (str[i + 9] == '#')
				return ("j4");
			//4th block left of 2nd
			if (str[i + 4] == '#')
				return ("t4");
		}
		//3rd block left of 2nd
		if (str[i + 4] == '#')
		{
			//4th block under 3rd
			if (str[i + 9] == '#')
				return ("z2");
			//4th block left of 3rd
			if (str[i + 3] == '#')
				return ("l3");
		}
	}
	return ("ERROR");
}
