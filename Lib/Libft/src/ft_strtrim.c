/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:39:53 by kquetat-          #+#    #+#             */
/*   Updated: 2023/11/09 20:05:23 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	dstsize;
	size_t	len;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1 == 0)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (s1[len - 1] && ft_strrchr(set, s1[len - 1]))
		len--;
	dstsize = len;
	dest = ft_substr(s1, 0, dstsize);
	return (dest);
}

/*int main(void)
{
	char *s1 = "        ";
	printf("|%s|", ft_strtrim(s1, " "));
	return (0);
}*/
