/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apenrose <apenrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:44:56 by apenrose          #+#    #+#             */
/*   Updated: 2020/12/16 19:41:34 by apenrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(ss = ((char *)malloc(len + 1))))
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		ss[0] = '\0';
		return (ss);
	}
	while (s && (i < len))
	{
		ss[i] = s[start];
		i++;
		start++;
	}
	ss[i] = '\0';
	//free(s);
	return (ss);
}

char		*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	count_s1;

	s2 = NULL;
	i = 0;
	count_s1 = 0;
	while (s1[count_s1])
	{
		count_s1++;
	}
	if (!(s2 = (char*)malloc(sizeof(char) * (count_s1 + 1))))
        return (NULL);
	while (i < count_s1)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}


int			ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
	    return (0);
	while (s[len])
		len++;
	return (len);
}

//char			*ft_strjoin(char *s1, char *s2)
//{
//    size_t		len;
//    char		*s;
//    size_t		i;
//
//    if (!s1 || !s2)
//        return (NULL);
//    len = ft_strlen(s1) + ft_strlen(s2);
//    if (!(s = (char*)malloc((len + 1) * sizeof(char))))
//        return (NULL);
//    i = 0;
//    while (i < len)
//    {
//        if (*s1)
//            s[i] = *(s1++);
//        else
//            s[i] = *(s2++);
//        i++;
//    }
//    s[i] = '\0';
//    return (s);
//}

char		*ft_strjoin(char *s1, char *s2)
{
    char	*uni;
    int		sum;
    int		g;
    int		i;

    i = 0;
    g = 0;
    sum = 0;
    if (!(s2))
        return (NULL);
    sum = ft_strlen(s1) + ft_strlen(s2);
    if (!(uni = ((char *)malloc(sum + 1))))
        return (NULL);
    while (s1 && s1[i])
    {
        uni[g] = s1[i];
        i++;
        g++;
    }
    i = 0;
    while (s2[i])
    {
        uni[g] = s2[i];
        i++;
        g++;
    }
    uni[g] = '\0';
    return (uni);
}
