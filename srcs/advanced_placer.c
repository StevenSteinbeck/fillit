/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_placer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +.+  +:+       +.+        */
/*                                                +.+.+.+.+.+   +.+           */
/*   Created: 2018/03/15 10:10:53 by stestein          .+.    .+.             */
/*   Updated: 2018/04/10 12:42:52 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*advanced_placer(char **str, int row, int i, int skipper)
{
	while (str[row][i])
	{
		if (str[row][i] == '.')
			break ;
		i++;
	}
	//2nd block next to 1st
	if (str[row][i + 1] == '.')
	{
		//3rd block under 1st
		if (str[row + 1][i] == '.')
		{
			//4th block under 2nd
			if (str[row + 1][i + 1] == '.' && skipper == 0)
				return ("o");
			//4th block under 3rd
			if (str[row + 2][i] == '.' && skipper == 1)
				return ("j2");
			//4th block next to 2nd
			if (str[row][i + 2] == '.' && skipper == 2)
				return ("l1");
		}
		//3rd block under 2nd
		if (str[row + 1][i + 1] == '.')
		{
			//4th block next to 3rd
			if (str[row + 1][i + 2] == '.' && skipper == 3)
				return ("z1");
			//4th block under 3rd
			if (str[row + 2][i + 1] == '.' && skipper == 4)
				return ("l4");
			//4th block next to 2nd
			if (str[row][i + 2] == '.' && skipper == 5)
				return ("t1");
		}
		//3rd block next to 2nd
		if (str[row][i + 2] == '.')		
		{
			//4rth block next to 3rd
			if (str[row][i + 3] == '.' && skipper == 6)
				return ("i1");
			//4th block under 3rd
			if (str[row + 1][i + 2] == '.' && skipper == 7)
				return ("j1");
		}
		//3rd block under and to left of 1st
		if (str[row + 1][i - 1] == '.')
		{
			//4th block next to 3rd, under 1st
			if (str[row + 1][i] == '.' && skipper == 8)
				return ("s1");
		}
	}
	//2nd block under 1st
	if (str[row + 1][i] == '.')
	{
		//3rd block next to 2nd
		if (str[row + 1][i + 1] == '.')
		{
			//4th block under 3rd
			if (str[row + 2][i + 1] == '.' && skipper == 9)
				return ("s2");
			//4th block next to 3rd
			if (str[row + 1][i + 2] == '.' && skipper == 10)
				return ("j3");
			//4th block left of 2nd
			if (str[row + 1][i - 1] == '.' && skipper == 11)
				return ("t3");
			//4th block under 2nd
			if (str[row + 2][i] == '.' && skipper == 12)
				return ("t2");
		}
		//3rd block under 2nd
		if (str[row + 2][i] == '.')
		{
			//4th block under 3rd
			if (str[row + 3][i] == '.' && skipper == 13)
				return ("i2");
			//4th block right of 3rd
			if (str[row + 2][i + 1] == '.' && skipper == 14)
				return ("l2");
			//4th block left of 3rd
			if (str[row + 2][i - 1] == '.' && skipper == 15)
				return ("j4");
			//4th block left of 2nd
			if (str[row + 1][i - 1] == '.' && skipper == 16)
				return ("t4");
		}
		//3rd block left of 2nd
		if (str[row + 1][i - 1] == '.')
		{
			//4th block under 3rd
			if (str[row + 2][i - 1] == '.' && skipper == 17)
				return ("z2");
			//4th block left of 3rd
			if (str[row + 1][i - 2] == '.' && skipper == 18)
				return ("l3");
		}
	}
	return (0);
}
