/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:46:15 by khovakim          #+#    #+#             */
/*   Updated: 2022/03/26 20:30:42 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	if (s1)
		while (*s1)
			str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (count);
	while (s[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	b;
	int				i;

	if (!s)
		return (0);
	b = c;
	i = 0;
	while (s[i] != b && s[i])
		i++;
	if (s[i] == b)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*str1;
	size_t	len;

	len = 0;
	if (!s1)
		return (NULL);
	while (s1[len] != '\0')
		len++;
	str1 = (char *)malloc(sizeof(*str1) * (len + 1));
	if (str1 == NULL)
		return (0);
	len = 0;
	while (s1[len] != '\0')
	{
		str1[len] = s1[len];
		len++;
	}
	str1[len] = '\0';
	return (str1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	result = (char *)malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
