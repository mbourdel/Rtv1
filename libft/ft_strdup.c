/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:11:12 by mbourdel          #+#    #+#             */
/*   Updated: 2015/02/04 17:15:02 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		strlen;
	char	*strdup;

	i = 0;
	strlen = ft_strlen(str);
	strdup = (char*)malloc((strlen + 1) * sizeof(*str));
	strdup[strlen] = '\0';
	while (i <= strlen)
	{
		strdup[i] = str[i];
		i++;
	}
	return (strdup);
}
