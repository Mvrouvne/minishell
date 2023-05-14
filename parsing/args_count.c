/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaiba <machaiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:28:25 by machaiba          #+#    #+#             */
/*   Updated: 2023/05/14 15:28:26 by machaiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	args_count(t_token *lst)
{
	int				count;
	static t_token	*x;
	static int		y;

	count = 0;
	if (y)
	{
		lst = x;
	}
	while (lst)
	{
		
		if (lst->type == PIPE)
		{
			x = lst->next;
			y++;
			break ;
		}
		if (lst->type != INPUT && lst->type != OUTPUT
			&& lst->type != APPEND && lst->type != HEREDOC
			&& lst->type != DELIMITER)
			count++;
		lst = lst->next;
	}
	return (count);
}
