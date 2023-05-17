/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otitebah <otitebah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:12:27 by otitebah          #+#    #+#             */
/*   Updated: 2022/11/01 09:59:44 by otitebah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if ((i >= 48 && i <= 57) || (i >= 65 && i <= 90)
		|| (i >= 97 && i <= 122))
	{
		return (1);
	}
	else
		return (0);
}