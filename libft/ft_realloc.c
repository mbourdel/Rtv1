/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 17:10:29 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/22 16:54:49 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;

	if (ptr == NULL)
		return (NULL);
	if (size == 0)
		return (ptr);
	ret = malloc(sizeof(ptr) * (ft_strlen((char*)ptr) + size));
	ft_bzero(ret, ft_strlen((char*)ptr) + size);
	ret = ft_memcpy(ret, ptr, ft_strlen((char*)ptr));
	if (ret == NULL)
		return (ptr);
	free(ptr);
	return (ret);
}
