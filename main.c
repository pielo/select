/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 19:26:32 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/12 19:18:06 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>
#include <libft/includes/libft.h>
#include <stdio.h>

static void			ft_close(struct termios term)
{
	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
}

int					main(int argc, char **argv)
{
	struct termios	term;
	sel_list		lalist;
	char			*pos;

	term = ft_init();
	lalist = ft_init2(argc, argv);
	pos = tgetstr("cm", 0);
	tputs(tgoto(pos, 0, 0), 1, ft_putc);
	ft_all(lalist, argc, pos);
	ft_close(term);
	return (0);
}
