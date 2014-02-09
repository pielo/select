/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 20:09:03 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/12 18:57:55 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>

typedef struct	d_list
{
	int			x;
	int			y;
}				co_list;

typedef struct		n_list
{
	char			*word;
	int				select;
	int				first;
	struct n_list   *prec;
	struct n_list	*next;
}					sel_list;

struct termios		ft_init(void);
int					ft_putc(int c);
sel_list			ft_init2(int ac, char **av);
sel_list			ft_create(int ac, char **av);
void				ft_all(sel_list lalist, int argc, char *pos);
void				ft_aff(sel_list *lalist);

#endif
