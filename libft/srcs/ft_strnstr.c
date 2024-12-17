/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:36:44 by lde-merc          #+#    #+#             */
/*   Updated: 2024/11/27 13:56:04 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	big_size;
	char	*big2;

	big_size = ft_strlen(big);
	big2 = (char *)big;
	if (little[0] == '\0')
		return (big2);
	i = 0;
	while (i < len && big2[i])
	{
		j = 0;
		while (i + j < len && little[j])
		{
			if (little[j] != big2[i + j])
				break ;
			j++;
		}
		if (little[j] == '\0')
			return (&big2[i]);
		i++;
	}
	return (NULL);
}
