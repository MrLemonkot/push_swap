/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:05:00 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 21:05:28 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_1byte(char *new)
{
	new = (char *)malloc(sizeof(char) * 1);
	if (new == 0)
		return (0);
	new[0] = 0;
	return (new);
}

static int	new_start_index(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i] != 0)
		i++;
	return (i);
}

static int	new_end_index(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen((char *)s1) - 1;
	while (ft_strrchr(set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	new_strlen;

	if (s1 == NULL)
		return (NULL);
	new = 0;
	if (ft_strlen((char *)s1) == 0)
		return (malloc_1byte(new));
	if (s1[new_start_index(s1, set)] == '\0')
		return (malloc_1byte(new));
	new_strlen = new_end_index(s1, set) - new_start_index(s1, set) + 1;
	new = (char *)malloc(sizeof(char) * (new_strlen + 1));
	if (new == 0)
		return (0);
	ft_strlcpy(new, s1 + new_start_index(s1, set), new_strlen + 1);
	return (new);
}
