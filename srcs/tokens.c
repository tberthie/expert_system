/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:35:20 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 15:36:17 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert.h"

void				token_push(t_token ***tab, t_token *elem)
{
	t_token			**token;
	size_t			len;

	len = ft_arr_len((void**)*tab) + 2;
	token = ft_memalloc(sizeof(void*) * len);
	len -= 2;
	token[len] = elem;
	while (len--)
		token[len] = (*tab)[len];
	free(*tab);
	*tab = token;
}

