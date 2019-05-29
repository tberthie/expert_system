/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:34:51 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 15:35:01 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert.h"

void				ft_memset(void *dst, char c, size_t len)
{
	while (len--)
		*(char*)dst++ = c;
}

char				ft_strncmp(const char *s1, const char *s2, size_t bytes)
{
	while (bytes--)
		if (*s1++ != *s2++)
			return (1);
	return (0);
}

void				ft_memcpy(void *dst, void *src, size_t bytes)
{
	while (bytes--)
		*(char*)dst++ = *(char*)src++;
}

void				ft_strnpush(char **str, char *trail, size_t trail_len)
{
	size_t			len;
	char			*new;

	len = ft_strlen(*str);
	new = ft_memalloc(sizeof(char) * (len + trail_len + 1));
	ft_memcpy(new, *str, len);
	ft_memcpy(new + len, trail, trail_len);
	free(*str);
	*str = new;
}

size_t				ft_arr_len(void **tab)
{
	size_t			len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void				*ft_memalloc(size_t bytes)
{
	char			*ptr;

	if (!(ptr = (char*)malloc(bytes)))
		exit(1);
	while (bytes--)
		ptr[bytes] ^= ptr[bytes];
	return (ptr);
}

size_t				ft_strlen(const char *s)
{
	const char		*beg;

	beg = s;
	while (*s)
		s++;
	return ((size_t)(s - beg));
}
