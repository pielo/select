/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 11:46:02 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/10 16:30:18 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>
#include <libft/includes/libft.h>

struct termios		ft_init(void)
{
	char			*name;
	struct termios	term;

	name = getenv("TERM");
	tgetent(NULL, name);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	return (term);
}

sel_list			ft_init2(int ac, char **av)
{
	sel_list		llist;

	llist = ft_create(ac, av);
	tputs(tgetstr("ti", NULL), 1, ft_putc);
	tputs(tgetstr("us", NULL), 1, ft_putc);
	ft_putstr(llist.word);
	ft_putchar('\n');
	tputs(tgetstr("ue", NULL), 1, ft_putc);
	llist = *llist.next;
	while (llist.first != 1)
	{
		ft_putstr(llist.word);
		ft_putchar('\n');
		llist = *llist.next;
	}
	return (llist);
}
