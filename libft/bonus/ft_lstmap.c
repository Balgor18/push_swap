/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:43:18 by fcatinau          #+#    #+#             */
/*   Updated: 2021/06/26 14:40:26 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	a(t_list *new_lst, t_list *new_elem, t_list *lst)
{
	new_lst = new_elem;
	lst = lst->next;
}

void	too_many_line(t_list *lst, t_list *new_elem, t_list *new_lst
					, void (*d)(void *))
{
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&lst, d);
			ft_lstclear(&new_lst, d);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_elem);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	new_lst = NULL;
	if (!lst || !f)
		return (NULL);
	new_elem = ft_lstnew(f(lst->content));
	if (!new_elem)
	{
		ft_lstclear(&lst, d);
		return (NULL);
	}
	a(new_lst, new_elem, lst);
	too_many_line(lst, new_elem, new_lst, d);
	return (new_lst);
}
