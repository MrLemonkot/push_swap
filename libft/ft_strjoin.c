/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:04:09 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:11:30 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	newsize;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	newsize = len_s1 + len_s2 + 1;
	newstr = 0;
	newstr = (char *)malloc(sizeof(char) * newsize);
	if (newstr == 0)
		return (0);
	ft_strlcpy(newstr, s1, len_s1 + 1);
	ft_strlcpy(newstr + len_s1, s2, len_s2 + 1);
	return (newstr);
}
