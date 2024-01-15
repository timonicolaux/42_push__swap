/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:36:32 by tnicolau          #+#    #+#             */
/*   Updated: 2023/11/20 13:16:07 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			length;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main()
// {
// 	char	str[] = "abcd";

// 	printf("%s\n", ft_strmapi(str, add_one));
// }
