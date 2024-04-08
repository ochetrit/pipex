/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochetrit <ochetrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:04:33 by ochetrit          #+#    #+#             */
/*   Updated: 2024/03/25 11:44:11 by ochetrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	nb;

	if (!s)
		return (0);
	nb = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			nb++;
		while (*s != c && *s)
			s++;
	}
	return (nb);
}

static char	*ft_write_word(char const *s, char *dest, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	len = 0;
	while (*s != c && *s)
	{
		dest[len] = *s;
		len++;
		s++;
	}
	return (dest);
}

char	**ft_free(char **strs, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	len;
	size_t	i;

	len = ft_count_words(s, c);
	strs = (char **)malloc((len + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[len] = NULL;
	i = 0;
	while (i < len)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			strs[i] = ft_write_word(s, strs[i], c);
		if (!strs[i])
			return (ft_free(strs, i));
		while (*s != c && *s)
			s++;
		i++;
	}
	return (strs);
}

/*int main(int ac, char **av)
{
    (void)ac;
    int i = 0;
    char **strs = ft_split(av[1], av[2][0]);
    while (strs[i])
    {
        printf("%s\n", strs[i]);
        i++;
    }
}*/
