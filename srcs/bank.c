/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilnite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:10:44 by kvilnite          #+#    #+#             */
/*   Updated: 2018/03/21 14:08:08 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*store_input(char *str)
{
	int i;

	i = 0;
	if (str[i] == 'o')
		return ("##\n##\n");
	if (str[i] == 'i' && str[i + 1] == '1')
		return ("####\n");
	if (str[i] == 'i' && str[i + 1] == '2')
		return ("#\n#\n#\n#\n");
	if (str[i] == 's' && str[i + 1] == '1')
		return (".##\n##\n");
	if (str[i] == 's' && str[i + 1] == '2')
		return ("#\n##\n.#\n");
	if (str[i] == 'z' && str[i + 1] == '1')
		return ("##\n.##\n");
	if (str[i] == 'z' && str[i + 1] == '2')
        return (".#\n##\n#\n");
	if (str[i] == 'l' && str[i + 1] == '1')
		return ("###\n#\n");
    if (str[i] == 'l' && str[i + 1] == '2')
        return ("#\n#\n##\n");
    if (str[i] == 'l' && str[i + 1] == '3')
        return ("..#\n###\n");
    if (str[i] == 'l' && str[i + 1] == '4')
        return ("##\n.#\n.#\n");
	if (str[i] == 'j' && str[i + 1] == '1')
		return ("###\n..#\n");
	if (str[i] == 'j' && str[i + 1] == '2')
        return ("##\n#\n#\n");
	if (str[i] == 'j' && str[i + 1] == '3')
        return ("#\n###\n");
	if (str[i] == 'j' && str[i + 1] == '4')
        return (".#\n.#\n##\n");
	if (str[i] == 't' && str[i + 1] == '1')
		return ("###\n.#\n");
    if (str[i] == 't' && str[i + 1] == '2')
        return ("#\n##\n#\n");
    if (str[i] == 't' && str[i + 1] == '3')
        return (".#\n###\n");
    if (str[i] == 't' && str[i + 1] == '4')
        return (".#\n##\n.#\n");
	return (0);
}

char *convert(char *str, int a)
{
	int i;
	char *cpy;

	i = 0;
	cpy = (char *)malloc(sizeof(*cpy) * ft_strlen(str));
	cpy = ft_strcpy(cpy, str);
	while (cpy[i] != '\0')
	{
		if (cpy[i] == '#')
			cpy[i] = a;
		i++;
	}
	return (cpy);
}
