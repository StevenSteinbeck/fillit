/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilnite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:10:44 by kvilnite          #+#    #+#             */
/*   Updated: 2018/03/15 13:18:03 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*store_input(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'o')
			return ("AA..\nAA..\n....\n....");
		if (str[i] == 'i' && str[i + 1] == '1')
			return ("BBBB\n....\n....\n....");
		if (str[i] == 'i' && str[i + 1] == '2')
			return ("C...\nC...\nC...\nC...");
		if (str[i] == 's' && str[i + 1] == '1')
			return (".DD.\nDD..\n....\n....");
		if (str[i] == 's' && str[i + 1] == '2')
			return ("E...\nEE..\n.E..\n....");
		if (str[i] == 'z' && str[i + 1] == '1')
			return ("FF..\n.FF.\n....\n....");
        if (str[i] == 'z' && str[i + 1] == '2')
            return (".G..\nGG..\nG...\n....");
		if (str[i] == 'l' && str[i + 1] == '1')
			return ("HHH.\nH...\n....\n....");
        if (str[i] == 'l' && str[i + 1] == '2')
            return ("I...\nI...\nII..\n....");
        if (str[i] == 'l' && str[i + 1] == '3')
            return ("...J\nJJJ.\n....\n....");
        if (str[i] == 'l' && str[i + 1] == '4')
            return ("KK..\n.K..\n.K..\n....");
		if (str[i] == 'j' && str[i + 1] == '1')
			return ("LLL.\n..L.\n....\n....");
		if (str[i] == 'j' && str[i + 1] == '2')
            return ("MM..\nM...\nM...\n....");
		if (str[i] == 'j' && str[i + 1] == '3')
            return ("N...\nNNN.\n....\n....");
		if (str[i] == 'j' && str[i + 1] == '4')
            return (".O..\n.O..\nOO..\n....");
		if (str[i] == 't' && str[i + 1] == '1')
			return ("PPP.\n.P..\n....\n....");
        if (str[i] == 't' && str[i + 1] == '2')
            return ("R...\nRR..\nR...\n....");
        if (str[i] == 't' && str[i + 1] == '3')
            return (".S..\nSSS.\n....\n....");
        if (str[i] == 't' && str[i + 1] == '4')
            return (".T..\nTT..\n.T..\n....");
		i++;
	}
	return (0);
}
