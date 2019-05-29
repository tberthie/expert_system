/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:27:46 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 15:29:00 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert.h"

void				free_tokens(t_token **tokens)
{
	t_token			**tokens_beg;

	tokens_beg = tokens;
	while (*tokens)
		free(*tokens++);
	free(tokens_beg);
}
