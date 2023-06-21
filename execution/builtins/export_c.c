/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otitebah <otitebah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:57:58 by otitebah          #+#    #+#             */
/*   Updated: 2023/06/21 12:21:07 by otitebah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	print_export(t_list **saving_expo)
{
	t_list *tmp1;
	char **sp = NULL;
	char *add_quotes = NULL;
	char *add_quotes2 = NULL;
	char *final = NULL;
	char *add_egal = NULL;

	(*saving_expo) = sort_list(saving_expo);
	tmp1 = (*saving_expo);
	while ((*saving_expo))
	{
		if (search_egal((*saving_expo)->value) == 1)
		{
			sp = ft_split((*saving_expo)->value, '=');
			if (sp[1])
			{
				add_quotes = ft_strjoin("\"", sp[1]);
				add_quotes2 = ft_strjoin(add_quotes, "\"");
				add_egal = ft_strjoin("=", add_quotes2);
				final = ft_strjoin(sp[0], add_egal);
				free(add_quotes);
				free(add_quotes2);
				free(add_egal);
				// free(final);
			}
			else
			{
				final = (*saving_expo)->value;
				final = ft_strjoin((*saving_expo)->value, "\"");
				free(final);
			}
			ft_free(sp);
		}
		else
			final = (*saving_expo)->value;
		ft_putstr_fd("declare -x  ", 1);
		ft_putendl_fd(final, 1);
		// free(final);
		(*saving_expo) = (*saving_expo)->next;
		// free(final);
	}
	(*saving_expo) = tmp1;
}