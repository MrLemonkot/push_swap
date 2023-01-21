/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:41:44 by akayle            #+#    #+#             */
/*   Updated: 2022/03/25 19:37:59 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef    BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*buffer_line(int fd, char *line);
char	*before_n(char *remains);
char	*after_n(char *remains);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		ft_strchr(char *str, int ch);
char	*ft_strjoin(char *remains, char *buffer);
#endif