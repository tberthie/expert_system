/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:13:55 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 16:17:53 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert.h"
#include <unistd.h>

t_token				**parse_tokens(const char *data)
{
	t_token			**tab;
	t_token			*token;
	char			op;

	ft_log("loading tokens");
	tab = ft_memalloc(sizeof(void*));
	while (*data)
	{
		if (*data == COMMENT)
			while (*data && *data != '\n')
				data++;
		else if ((!ft_strncmp(data, "=>", 2) && (op = THEN)) ||
		(!ft_strncmp(data, "<=>", 3) && (op = THEN_IF)) ||
		(op = get_operator(*data)) != -1)
		{
			token = ft_memalloc(sizeof(t_token));
			token->op_code = op;
			token->letter = *data;
			data += (op == THEN) + (op == THEN_IF ? 2 : 0);
			token_push(&tab, token);
		}
		else if (*data != ' ' && *data != '\t' && *data != '\n')
			ft_error("invalid input file format");
		if (*data)
			data++;
	}
	return (tab);
}
