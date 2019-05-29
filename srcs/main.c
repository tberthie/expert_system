/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:02:37 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 15:31:35 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert.h"

int				main(int ac, char **av)
{
	char		*file_data;
	t_token		**tokens;

	if (ac != 2)
		ft_error("usage: \"./expert_system <input_file>\"");
	file_data = get_file_data(av[1]);
	tokens = parse_tokens(file_data);
	free(file_data);
	resolve(tokens);
	free_tokens(tokens);
	return (0);
}
