/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:05:05 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 13:19:00 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert.h"

char		get_operator(char c)
{
	int		op;

	op = 0;
	while (op < LETTER)
		if (c == OPERATORS[op++])
			return ((char)op - 1);
	return (c >= 'A' && c <= 'Z' ? LETTER : -1);
}
