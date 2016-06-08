/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 20:09:38 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/02 22:45:06 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*sortie;

	if (lst)
	{
		sortie = f(lst);
		sortie->next = ft_lstmap(lst->next, f);
		return (sortie);
	}
	return (NULL);
}
