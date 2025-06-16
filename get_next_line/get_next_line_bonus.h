/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:50:40 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/20 18:12:46 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE    1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char		*ft_strjoin(char const *s1, char const *s2);
ssize_t		ft_strlen(const char *s);
int			ft_strchr(char *s, char c);
char		*get_next_line(int fd);
char		*ft_fill_sta(char *sta, int fd);
char		*ft_fill_line(char *sta);
char		*ft_new_sta(char *sta);

#endif