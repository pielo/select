/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:13:29 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/12 18:52:41 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>
#include <libft/includes/libft.h>

void	ft_aff(sel_list *lalist)
{
	sel_list *beg;

	beg = lalist;
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	while (beg->first != 1)
		*beg = *beg->next;
	if (beg->select == 1)
	{
		ft_putstr(beg->word);
		ft_putchar(' ');
	}
	*beg = *beg->next;
	while (beg->first != 1)
	{
		if (beg->select == 1)
		{
			ft_putstr(beg->word);
			ft_putchar(' ');
		}
		*beg = *beg->next;
	}
}
