/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:50:44 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 15:32:09 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert.h"
#include <unistd.h>

static void		output_result(t_expert *expert)
{
	int			i;
	char		c;

	i = 0;
	write(1, "\n", 1);
	while (i < 26)
	{
		if (expert->query[i])
		{
			c = (char)i + 'A';
			write(1, &c, 1);
			if (expert->reg[i] == R_FALSE)
				ft_putstr(" is false\n");
			else if (expert->reg[i] == R_TRUE)
				ft_putstr(" is true\n");
			else
				ft_putstr(" is undefined\n");
		}
		i++;
	}
}

static void		parse_init(t_token **tokens, t_expert *expert)
{
	int			offset;

	offset = (int)ft_arr_len((void**)tokens) - 1;
	if (offset <= 0)
		ft_error("invalid input file format");
	ft_memset(expert->query, 0, 26);
	while (offset && tokens[offset]->op_code != QUERY)
	{
		if (tokens[offset]->op_code != LETTER)
			ft_error("invalid query format");
		expert->query[tokens[offset]->letter - 'A'] = 1;
		free(tokens[offset--]);
	}
	if (!offset)
		ft_error("invalid query format");
	free(tokens[offset--]);
	ft_memset(expert->reg, 0, 26);
	while (offset && tokens[offset]->op_code != EQUAL)
	{
		if (tokens[offset]->op_code != LETTER)
			ft_error("invalid initialisation format");
		expert->reg[tokens[offset]->letter - 'A'] = R_TRUE;
		free(tokens[offset--]);
	}
	if (!offset)
		ft_error("invalid initialisation format");
	free(tokens[offset]);
	tokens[offset] = 0;
}

void			resolve(t_token **tokens)
{
	t_expert	*expert;

	expert = ft_memalloc(sizeof(t_expert));
	parse_init(tokens, expert);
	parse_rules(tokens, expert);
	output_result(expert);
	free(expert);
}
