/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thclarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:58:49 by thclarac          #+#    #+#             */
/*   Updated: 2023/02/14 15:38:53 by thclarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*anew_lst;

	anew_lst = NULL;
	while (lst != NULL)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (new_lst == NULL)
		{
			ft_lstclear(&anew_lst, del);
			break ;
		}
		ft_lstadd_back(&anew_lst, new_lst);
		lst = lst->next;
	}
	return (anew_lst);
}
