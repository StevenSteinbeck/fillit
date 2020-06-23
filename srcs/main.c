/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:48:44 by stestein          #+#    #+#             */
/*   Updated: 2018/04/11 17:24:40 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

t_blk	*ft_storage(char *str)
{
	t_blk	*block;
	t_blk	*tmp;

	STORAGE;
	i = ft_basic_check(str);
	if ((block = (t_blk *)malloc(sizeof(t_blk))) == 0)
		return (NULL);
	tmp = block;
	while (i-- > 0)
	{
		tmp->str = ft_strndup(&str[j], 20);
		ft_supercheck(tmp->str);
		tmp->c = ++c;
		j += 21;
		if (!(tmp->next = (t_blk *)malloc(sizeof(t_blk))))
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (block);
}

char	*ft_reader(char *file)
{
	READER;
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while ((read_report = read(fd, buffer, 1)))
	{
		tmp[i++] = buffer[0];
		if (i > 546)
			ft_error();
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_error();
	return (ft_strdup(tmp));
}

int		main(int argc, char *argv[])
{
	t_blk	*block;
	char	*read;
	char	**result;
	int		i;

	i = 0;
	if (argc != 2)
		ft_error();
	read = ft_reader(argv[1]);
	if (read == 0)
		ft_error();
	block = ft_storage(read);
	block = ft_default_xy(block);
	result = ft_result(block, ft_max_size(block));
	free(block);
	while (result[i])
	{
		ft_putendl(result[i]);
		i++;
	}
	return (0);
}
