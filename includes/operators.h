/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:56:21 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 16:26:16 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORS_H
# define OPERATORS_H

# define COMMENT	'#'
# define OPERATORS	"()!+|^=?"

enum			e_operators {
	PAR_IN,
	PAR_OUT,
	NOT,
	AND,
	OR,
	XOR,
	EQUAL,
	QUERY,
	LETTER,
	THEN,
	THEN_IF,
	OP_SPLIT
};

#endif
