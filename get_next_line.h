/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:36:17 by sminna            #+#    #+#             */
/*   Updated: 2021/10/20 20:37:52 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line_second_part(int *xx, char *str, char *strfull, int fd);
char	*ft_end_of_get_next_line(char *end, char *statka, char *str);
char	*get_next_line_free_part(char *s1, char *s2);
char	*get_next_line_main_part(int fd, char *str, int xx, char *end);
char	*get_next_line(int fd);
char	*ft_strjoin_for_gnl(char *s1, char *s2, int r);
size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *b, size_t len);
char	*ft_strdup(const char *s1);

#endif
