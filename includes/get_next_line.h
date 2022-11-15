/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:35:45 by kshim             #+#    #+#             */
/*   Updated: 2022/09/22 09:38:49 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512

#  include <stddef.h>

size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strndup(const char *s1, size_t n);

int			get_next_line(int fd, char **ret_str);

# endif
#endif