/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:01:21 by tberthie          #+#    #+#             */
/*   Updated: 2019/05/29 15:40:29 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_H
# define EXPERT_H

# include <stdlib.h>

# include "operators.h"

# define NAME	"expert_system"

typedef struct	s_token
{
	char		op_code;
	char		letter;

}				t_token;

enum			e_reg_state {
	R_FALSE, R_TRUE, R_UNDEF
};

typedef struct	s_rule
{
	t_token		**input;
	t_token		**output;

}				t_rule;

typedef struct	s_expert
{
	char		reg[26];
	char		query[26];
	t_rule		***rules;

}				t_expert;

char			get_operator(char c);

char			*get_file_data(const char *path);

t_token			**parse_tokens(const char *data);

void			resolve(t_token **tokens);
void			parse_rules(t_token **tokens, t_expert *expert);

void			free_tokens(t_token **tokens);

void			ft_error(const char *s, ...);
void			ft_log(const char *s);	

void			token_push(t_token ***arr, t_token *elem);

void			ft_putstr(const char *s);
size_t			ft_arr_len(void **tab);
void			*ft_memalloc(size_t bytes);
size_t			ft_strlen(const char *s);
void			ft_strnpush(char **str, char *trail, size_t trail_len);
void			ft_memcpy(void *dst, void *src, size_t bytes);
char			ft_strncmp(const char *s1, const char *s2, size_t bytes);
void			ft_memset(void *dst, char c, size_t len);

#endif
