/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:22:50 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 15:31:24 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert.h"
#include <fcntl.h>
#include <unistd.h>

char			*get_file_data(const char *path)
{
	char		*data;
	char		buffer[100];
	int			fd;
	int			rd;

	ft_log("loading input");
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error("cannot read from file \"%\"", path);
	data = ft_memalloc(sizeof(char));
	while ((rd = (int)read(fd, buffer, 100)) > 0)
		ft_strnpush(&data, buffer, (size_t)rd);
	if (rd == -1)
		ft_error("an error occured while reading file \"%\"", path);
	close(fd);
	return (data);
}
