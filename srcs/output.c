/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:21:00 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 15:22:21 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert.h"
#include <stdarg.h>
#include <unistd.h>

void			ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}

void			ft_error(const char *s, ...)
{
	va_list		ap;

	write(1, "expert_system [ERR]: ", 21);
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
			ft_putstr(va_arg(ap, const char *));
		else
			write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
	va_end(ap);
	exit(1);
}

void			ft_log(const char *s)
{
	write(1, "expert_system [LOG]: ", 21);
	ft_putstr(s);
	write(1, "\n", 1);
}
	
