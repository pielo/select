/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 13:55:57 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/12 17:15:49 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>
#include <libft/includes/libft.h>

static sel_list	*ft_root(char *str)
{
	sel_list	*lst;

	lst = (sel_list *)malloc(sizeof(*lst));
	if (str == NULL)
		lst->word = NULL;
	else
	{
		lst->word = ft_strnew(1);
		lst->word = ft_strjoin(lst->word, str);
	}
	lst->first = 1;
	lst->select = 0;
	lst->prec = (sel_list *)malloc(sizeof(*lst));
	lst->prec = lst;
	lst->next = (sel_list *)malloc(sizeof(*lst));
	lst->next = lst;
	return (lst);
}

void			ft_add(sel_list *lst, char *str)
{
	sel_list	*new;

	new = (sel_list *)malloc(sizeof(*new));
	if (str == NULL)
		new->word = NULL;
	else
	{
		new->word = ft_strnew(1);
		new->word = ft_strjoin(new->word, str);
	}
	new->first = 0;
	new->select = 0;
	if (lst != NULL)
	{
		new->prec = (sel_list *)malloc(sizeof(*new));
		new->prec = (lst)->prec;
		new->next = (sel_list *)malloc(sizeof(*new));
		new->next = lst;
		(lst)->prec->next = new;
		(lst)->prec = new;
	}
}

sel_list		ft_create(int ac, char **av)
{
	sel_list	*llist;
	int			i;

	i = 2;
	llist = ft_root(av[1]);
	while (i < ac)
	{
		ft_add(llist, av[i]);
		i++;
	}
	return (*llist);
}
