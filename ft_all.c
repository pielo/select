/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 16:36:14 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/12 19:19:28 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>
#include <libft/includes/libft.h>

static void	ft_down(sel_list *lalist, int argc, co_list *coord, char *pos)
{
	if ((*coord).y + (*coord).x == argc - 2)
	{
		(*coord).x = 0;
		(*coord).y = 0;
	}
	else
		(*coord).y += 1;
	tputs(tgetstr("ce", NULL), 1, ft_putc);
	if ((*lalist).select == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putc);
	ft_putstr((*lalist).word);
	tputs(tgetstr("me", NULL), 1, ft_putc);
	tputs(tgoto(pos, (*coord).x, (*coord).y), 1, ft_putc);
	*lalist = *(*lalist).next;
	tputs(tgetstr("ce", NULL), 1, ft_putc);
	if ((*lalist).select == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putc);
	tputs(tgetstr("us", NULL), 1, ft_putc);
	ft_putstr((*lalist).word);
	tputs(tgetstr("me", NULL), 1, ft_putc);
	tputs(tgoto(pos, (*coord).x, (*coord).y), 1, ft_putc);
}

static void	ft_up(sel_list *lalist, int argc, co_list *coord, char *pos)
{
	if ((*coord).y == 0)
		(*coord).y = argc - 2;
	else
		(*coord).y -= 1;
	tputs(tgetstr("ce", NULL), 1, ft_putc);
	if ((*lalist).select == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putc);
	ft_putstr((*lalist).word);
	tputs(tgetstr("me", NULL), 1, ft_putc);
	tputs(tgoto(pos, (*coord).x, (*coord).y), 1, ft_putc);
	*lalist = *(*lalist).prec;
	tputs(tgetstr("ce", NULL), 1, ft_putc);
	if ((*lalist).select == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putc);
	tputs(tgetstr("us", NULL), 1, ft_putc);
	ft_putstr((*lalist).word);
	tputs(tgetstr("me", NULL), 1, ft_putc);
	tputs(tgoto(pos, (*coord).x, (*coord).y), 1, ft_putc);
}

static void	ft_space(sel_list *lalist, co_list *coord, char *pos)
{
	tputs(tgetstr("ce", NULL), 1, ft_putc);
	tputs(tgoto(pos, (*coord).x, (*coord).y), 1, ft_putc);
	if ((*lalist).select == 0)
	{
		(*lalist).select = 1;
		tputs(tgetstr("mr", NULL), 1, ft_putc);
		tputs(tgetstr("us", NULL), 1, ft_putc);
		ft_putstr((*lalist).word);
		tputs(tgetstr("me", NULL), 1, ft_putc);
		tputs(tgoto(pos, (*coord).x, (*coord).y), 1, ft_putc);
	}
}

void		ft_all(sel_list lalist, int argc, char *pos)
{
	char	read_char[5] = {0};
	co_list	coord;

	coord.x = 0;
	coord.y = 0;
	while (!(*(unsigned int *)read_char == 27))
	{
		tputs(tgetstr("vi", NULL), 1, ft_putc);
		if (*(unsigned int *)read_char == 32)
			ft_space(&lalist, &coord, pos);
		if (*(unsigned int *)read_char == 4348699)
			ft_down(&lalist, argc, &coord, pos);
		if (*(unsigned int *)read_char == 4283163)
			ft_up(&lalist, argc, &coord, pos);
		if (*(unsigned int *)read_char == 10)
		{
			ft_aff(&lalist);
			exit(0);
		}
		ft_bzero(read_char, 5);
		read(0, read_char, 4);
	}
	tputs(tgetstr("te", NULL), 1, ft_putc);
}
