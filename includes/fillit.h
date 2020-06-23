/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 10:22:49 by stestein          #+#    #+#             */
/*   Updated: 2018/04/11 13:50:41 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define READER int fd; int read_report; int i; char tmp[546]; char buffer[1];
# define STORAGE int i; int j = 0; char c = 64;

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct		s_blk
{
	char			c;
	char			*str;
	int				x[4];
	int				y[4];
	struct s_blk	*next;
}					t_blk;

void				ft_error(void);
char				*ft_reader(char *file);
t_blk				*ft_storage(char *str);
int					ft_basic_check(char *reading);
void				ft_supercheck(char *s);
t_blk				*ft_default_xy(t_blk *block);
int					ft_max_size(t_blk *block);
char				**ft_fill_empty(char **tab, int max);
t_blk				*ft_update_xy(t_blk *block, int x, int y);
char				**ft_result(t_blk *block, int max);
char				*ft_strndup(const char *s, size_t n);

#endif
