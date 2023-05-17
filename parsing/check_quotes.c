/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:16:31 by machaiba          #+#    #+#             */
/*   Updated: 2023/05/17 23:19:10 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_quotes(t_token **lst, char *line, int *x)
{
	char *str;

	str = malloc (sizeof(char));
	str[0] = '\0';
	int	d_quote = 0;
	int	s_quote = 0;
	while (line[*x])
	{
		if (line[*x] == '"')
		{
			if (s_quote == 1)
				str = ft_chrjoin(str, line[*x]);
			d_quote++;
		}
		else if (line[*x] == '\'')
		{
			if (d_quote == 1)
				str = ft_chrjoin(str, line[*x]);
			s_quote++;
		}
		else if (line[*x] == ' ' || line[*x] == '\t')
			(*x)++;
		else
			str = ft_chrjoin(str, line[*x]);
		(*x)++;
	}
	if (str)
		ft_lstadd_back(lst, ft_lstnew(str));
	return (0);
}
