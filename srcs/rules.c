/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:32:11 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 16:26:14 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert.h"

static const char	g_validation[] = {
	LETTER, NOT,									// PAR_IN
	OP_SPLIT, AND, OR, XOR, THEN, THEN_IF,			// PAR_OUT
	OP_SPLIT, PAR_IN, LETTER,						// NOT
	OP_SPLIT, PAR_IN, NOT, LETTER,					// AND
	OP_SPLIT, PAR_IN, NOT, LETTER,					// OR
	OP_SPLIT, PAR_IN, NOT, LETTER,					// XOR
	OP_SPLIT,										// EQUAL
	OP_SPLIT,										// QUERY
	OP_SPLIT, AND, OR, XOR, THEN, THEN_IF, PAR_OUT,	// LETTER
	OP_SPLIT, PAR_IN, NOT, LETTER,					// THEN
	OP_SPLIT, PAR_IN, NOT, LETTER,					// THEN_IF
	OP_SPLIT
};

static char		validate_syntax(t_token **tokens, int offset)
{
	const char	*rules;
	int			rules_offset;

	rules = g_validation;
	rules_offset = tokens[offset]->op_code;
	while (rules_offset--)
	{
		while (*rules != OP_SPLIT)
			rules++;
		rules++;
	}
	while (*rules != OP_SPLIT)
	{
		if (*rules == tokens[offset + 1]->op_code)
			return (1);
		rules++;
	}
	return (0);
}

void			parse_rules(t_token **tokens, t_expert *expert)
{
	int			offset;

	ft_log("loading rules");
	offset = 0;
	expert->rules = ft_memalloc(sizeof(void*));
	while (tokens[offset])
	{
		// split before validation
		if (tokens[offset + 1] && !validate_syntax(tokens, offset))
		{
			ft_error("invalid rule format");
		}
		// split then interpret
		offset++;
	}
}
